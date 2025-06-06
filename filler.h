/**
 * @file        filler.h
 * @description Definition of a filler namespace.
 * 
 *              THIS FILE WILL NOT BE SUBMITTED
 */

#ifndef _FILLER_H_
#define _FILLER_H_

#include <iostream>
#include <vector> // if it might be useful

#include "cs221util/PNG.h"

#include "animation.h"
#include "colourPicker.h"
#include "queue.h"
#include "stack.h"

using namespace std;
using namespace cs221util;

/**
 * filler namespace: specifies a set of functions for performing flood
 * fills on images.
 */
namespace filler
{

	/**
	 * Struct to store configuration variables for filler function.
	 */
	struct FillerConfig
	{
		int frameFreq;                               // Frequency with which to save frames to GIF animation.
		double tolerance;                            // Tolerance used to determine if pixel is in fill region.
		PNG img;                                     // Image to perform the fill on.
		pair<unsigned int, unsigned int> seedpoint;  // Seed location where the fill will begin.
		RGBAPixel seedcolour;                        // colour of the seed point
		ColourPicker* picker;                        // ColourPicker used to fill the region.
	};

	/**
	 * Performs a flood fill using breadth first search.
	 *
	 * @param config FillerConfig struct to setup the fill.
	 * @return animation object illustrating progression of flood fill algorithm.
	 */
	animation FillBFS(FillerConfig& config);

	/**
	 * Performs a flood fill using depth first search.
	 *
	 * @param config FillerConfig struct to setup the fill.
	 * @return animation object illustrating progression of flood fill algorithm.
	 */
	animation FillDFS(FillerConfig& config);

	/**
	 * Run a flood fill on an image starting at the seed point.
	 *
	 * @param config FillerConfig struct with data for flood fill of image.
	 * @return animation object illustrating progression of flood fill algorithm.
	 */
	template <template <class T> class OrderingStructure> animation Fill(FillerConfig& config);

	// Add any helper functions you need to "filler-private.h"
	#include "filler-private.h"

} // namespace filler

#include "filler.cpp"

#endif
