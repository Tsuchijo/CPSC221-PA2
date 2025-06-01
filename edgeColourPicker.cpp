/**
 * @file edgeColourPicker.cpp
 * @description Implements the EdgeColourPicker constructor and () function
 *              for CPSC 221 PA2
 *
 *              THIS FILE WILL BE SUBMITTED
 */

#include "edgeColourPicker.h"

/**
 * Constructs a new EdgeColourPicker.
 *
 * @param width        Number of pixels to colour around edge.
 * @param inputimage   Image for referencing original image colours.
 * @param scolour      Colour of seed point
 * @param ecolour      Colour to be used for painting the fill edge.
 * @param tol          Tolerance used to determine the edge of the fill.
 */
EdgeColourPicker::EdgeColourPicker(unsigned int width, PNG& inputimage, RGBAPixel scolour, RGBAPixel ecolour, double tol)
{
    edgewidth = width;
    img = inputimage;
    seedcolour = scolour;
    edgecolour = ecolour;
    tolerance = tol;
	
}

/**
 * Picks the colour for pixel at point p. If the x or y coordinate is
 * at or within an Euclidean radius of edgewidth pixels from the edge of
 * the fill region, it will be coloured with the required edge color.
 * Otherwise, its colour will not be changed.
 *
 * @param p   The point for which you're picking a colour.
 * @return    The colour chosen for (p).
 */
RGBAPixel EdgeColourPicker::operator()(pair<unsigned int, unsigned int> p)
{
    for(int i = -edgewidth; i <= int(edgewidth); i++){
        for(int j = -edgewidth; j <= int(edgewidth); j++){
            if((i*i + j*j) > (edgewidth*edgewidth)){
                continue;
            }
            int x = p.first + i;
            int y = p.second + j;
            if(!IsFill(x, y)){
                return edgecolour;
            }
        }
    }
    return *img.getPixel(p.first, p.second);
}

bool EdgeColourPicker::IsFill(int x, int y){
    int imageWidth = img.width();
    int imageHeight = img.height();
    if(x < 0 || x >= imageWidth || y < 0 || y >= imageHeight){
        return false;
    }
    RGBAPixel* imgcolour = img.getPixel(x, y);
    return imgcolour->distanceTo(seedcolour) <= tolerance;
}

/**
 * Add your private EdgeColourPicker function implementations and/or attributes below
 */
