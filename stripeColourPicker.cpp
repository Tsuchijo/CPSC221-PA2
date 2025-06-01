/**
 * @file stripeColourPicker.cpp
 * @description Implements the StripeColourPicker constructor and () function
 *              for CPSC 221 PA2
 *
 *              THIS FILE WILL BE SUBMITTED
 */

#include "stripeColourPicker.h"

/**
 * Constructs a new StripeColourPicker.
 *
 * @param stripe_width The width of each alternating stripe, in pixels
 * @param stripe_colour1 Colour of the main stripe
 * @param stripe_colour2 Colour of the alternate stripe
 */
StripeColourPicker::StripeColourPicker(unsigned int stripe_width, RGBAPixel stripe_colour1, RGBAPixel stripe_colour2)
{
    // Complete your implementation below
	colour1 = stripe_colour1;
    colour2 = stripe_colour2;
    stripewidth = stripe_width;
}

/**
 * Picks the colour for pixel (x, y).
 *
 * The stripe pattern to be drawn consists of alternating stripes each of stripewidth pixels,
 * in a 45-degree forward slash orientation.
 * e.g.  / / / / / 
 *        / / / / /
 *       / / / / / 
 *        / / / / /
 *
 * For reference, coordinate (0, 0) will be the left-most pixel of a colour1 stripe.
 */
RGBAPixel StripeColourPicker::operator()(pair<unsigned int, unsigned int> p)
{
    unsigned int x = p.first;
    unsigned int y = p.second;
    bool is_stripe = ((x + y) % (2 * stripewidth)) <= stripewidth;
    if(is_stripe){
        return colour1;
    }
    else{
        return colour2;
    }
}

/**
 * Add your private StripeColourPicker function implementations and/or attributes below
 */
