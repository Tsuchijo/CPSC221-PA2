/**
 * @file photoNegativeColourPicker.cpp
 * @description Implements the PhotoNegativeColourPicker constructor and () function
 *              for CPSC 221 PA2
 *
 *              THIS FILE WILL BE SUBMITTED
 */

#include "photoNegativeColourPicker.h"

 /**
  * Constructs a new PhotoNegativeColourPicker.
  */
PhotoNegativeColourPicker::PhotoNegativeColourPicker(PNG& orig)
{
    original = orig;
}

/**
 * Picks the colour for pixel p at coordinates (x, y).
 *
 * A "photo-negative" effect will be applied each R/G/B colour channel of
 * pixel p's original colour. The alpha channel should remain unchanged.
 * 
 * It will be up to you to decide what a suitable "negative" effect should be
 * in the RGB colour space.
 */
RGBAPixel PhotoNegativeColourPicker::operator()(pair<unsigned int, unsigned int> p)
{
    RGBAPixel *pixel = original.getPixel(p.first, p.second);
    unsigned int negative_r = 255 - pixel->r;
    unsigned int negative_g = 255 - pixel->g;
    unsigned int negative_b = 255 - pixel->b;
    return RGBAPixel(negative_r, negative_g, negative_b);
}

/**
 * Add your private PhotoNegativeColourPicker function implementations and/or attributes below
 */
