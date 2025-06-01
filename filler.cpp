/**
 * @file        filler.cpp
 * @description Implementation of functions in the filler namespace.
 *
 *              SUBMIT THIS FILE WITH YOUR MODIFICATIONS
 */

#include <map>
/**
 * Performs a flood fill using breadth first search.
 *
 * @param config FillerConfig struct to setup the fill
 * @return animation object illustrating progression of flood fill algorithm
 */
animation filler::FillBFS(FillerConfig& config) {
	// complete your implementation below
	// You should replace the following line with a
	// correct call to fill.
	return Fill<Queue>(config);
}

/**
 * Performs a flood fill using depth first search.
 *
 * @param  config - FillerConfig struct to setup the fill
 * @return animation object illustrating progression of flood fill algorithm
 */
animation filler::FillDFS(FillerConfig& config) {
	// complete your implementation below
	// You should replace the following line with a
	// correct call to fill.
	return Fill<Stack>(config);
}

/**
 * Run a flood fill on an image starting at the seed point
 *
 * @param config FillerConfig struct with data for flood fill of image
 * @return animation object illustrating progression of flood fill algorithm
 */
template <template <class T> class OrderingStructure> animation filler::Fill(FillerConfig& config)
{
	/**
	 * You need to implement this function!
	 *
	 * This is the basic description of a flood-fill algorithm: Every fill
	 * algorithm requires an ordering structure, which is passed to this
	 * function via its template parameter. For a breadth-first-search
	 * fill, that structure is a Queue, for a depth-first-search, that
	 * structure is a Stack. To begin the algorithm, you simply place the
	 * given point in the ordering structure, marking it processed
	 * (the way you mark it is a design decision you'll make yourself).
	 * We have a choice to either change the color, if appropriate, when we
	 * add the point to the OS, or when we take it off. In our test cases,
	 * we have assumed that you will change the color when a point is removed
	 * from the structure.
	 * Until the structure is empty, you do the following:
	 *
	 * 1.     Remove a point from the ordering structure, and then...
	 *
	 *        1.1.  add its unprocessed neighbors (up/down/left/right) whose color values are
	 *              within (or equal to) tolerance distance from the seed point,
	 *              to the ordering structure, and
	 *              mark them as processed.
	 *        1.2.  if it is an appropriate frame, send the current PNG to the
	 *              animation (as described below).
	 *
	 * 2.     When implementing your breadth-first-search and
	 *        depth-first-search fills, you will need to explore neighboring
	 *        pixels (up/down/left/right) in some order.
	 *
	 *        While the order in which you examine neighbors does not matter
	 *        for a proper fill, you must use the same order as we do for
	 *        your animations to come out like ours! The order you should put
	 *        neighboring pixels **ONTO** the queue or stack is as follows:
	 *        2.1. northern neighbour (up)
	 *        2.2. southern neighbour (down)
	 *        2.3. western neighbour (left)
	 *        2.4. eastern neighbour (right)
	 * 
	 *        If you process the neighbours in a different order, your fill may
	 *        still work correctly, but your animations will be different
	 *        from the grading scripts!
	 *
	 * 3.     For every k pixels filled, **starting at the kth pixel**, you
	 *        must add a frame to the animation, where k = frameFreq.
	 *
	 *        For example, if frameFreq is 4, then after the 4th pixel has
	 *        been filled you should add a frame to the animation, then again
	 *        after the 8th pixel, etc.  You must only add frames for the
	 *        number of pixels that have been filled, not the number that
	 *        have been checked. So if frameFreq is set to 1, a pixel should
	 *        be filled every frame.
	 *
	 * 4.     Finally, as you leave the function, send one last frame to the
	 *        animation. This frame will be the final result of the fill, and
	 *        it will be the one we test against.
	 *
	 */
	int framecount = 0; // increment after processing one pixel; used for producing animation frames (step 3 above)
	animation anim;
	ColourPicker& picker = *config.picker;
	OrderingStructure<pair<unsigned int, unsigned int>> os;
	std::map<pair<unsigned int, unsigned int>, bool> visited;
	os.Add(config.seedpoint);
	
	while(!os.IsEmpty()){
		pair<unsigned int, unsigned int> point = os.Remove();
		auto lookup = visited.find(point);
		if(lookup != visited.end()){
			continue;
		}
		int x = point.first;
		int y = point.second;
		bool isInFill = IsFill(x,y, config);
		visited[point] = isInFill;
		if(isInFill){
			RGBAPixel* pixel = config.img.getPixel(x, y);
			*pixel = picker(point);
			if(framecount % config.frameFreq == 0)
			{
				anim.addFrame(config.img);
			}
			pair<unsigned int, unsigned int> north = pair<unsigned int, unsigned int>(x, y - 1);
			pair<unsigned int, unsigned int> south = pair<unsigned int, unsigned int>(x, y + 1);
			pair<unsigned int, unsigned int> west = pair<unsigned int, unsigned int>(x - 1, y);
			pair<unsigned int, unsigned int> east = pair<unsigned int, unsigned int>(x + 1, y);
			os.Add(north);
			os.Add(south);
			os.Add(east);
			os.Add(west);
			++framecount;
		}
	}
	anim.addFrame(config.img);
	return anim;
}

bool filler::IsFill(int x, int y, FillerConfig& config){
    int imageWidth = config.img.width();
    int imageHeight = config.img.height();
    if(x < 0 || x >= imageWidth || y < 0 || y >= imageHeight){
        return false;
    }
    RGBAPixel* imgcolour = config.img.getPixel(x, y);
    return config.seedcolour.distanceTo(*imgcolour) <= config.tolerance;
}