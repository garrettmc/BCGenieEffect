//
//  UIView+Genie.h
//  BCGenieEffect
//
//  Created by Bartosz Ciechanowski on 23.12.2012.
//  Copyright (c) 2012 Bartosz Ciechanowski. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSUInteger, BCRectEdge) {
    BCRectEdgeTop    = 0,
    BCRectEdgeLeft   = 1,
    BCRectEdgeBottom = 2,
    BCRectEdgeRight  = 3
};

@interface UIView (Genie)

/*
 * After the animation has completed the view's transform will be changed to match the destination's rect, i.e.
 * view's transform (and thus the frame) will change, however the bounds and center will *not* change.
 */
- (void)genieInTransitionSnapshot:(UIImage *)image
                           toView:(UIView *)view
                     belowSubView:(UIView *)belowSubView
                     withDuration:(NSTimeInterval)duration
                  destinationRect:(CGRect)destRect
                  destinationEdge:(BCRectEdge)destEdge
                       completion:(void (^)())completion;

/*
 * Calls genieInTransitionToView:self.superview belowSubView:self ...
 */
- (void)genieInTransitionWithDuration:(NSTimeInterval)duration
                      destinationRect:(CGRect)destRect
                      destinationEdge:(BCRectEdge)destEdge
                           completion:(void (^)())completion;





/*
 * After the animation has completed the view's transform will be changed to CGAffineTransformIdentity.
 * I altered this to add a toView and belowSubView to let you genie a window in to a non-superview.
 */
- (void)genieOutTransitionSnapshot:(UIImage *)image
                            toView:(UIView *)view
                      belowSubView:(UIView *)belowSubView
                      withDuration:(NSTimeInterval)duration
                         startRect:(CGRect)startRect
                         startEdge:(BCRectEdge)startEdge
                        completion:(void (^)())completion;

/*
 * Calls sgenieOutTransitionToView:self.superview belowSubView:self ...
 */
- (void)genieOutTransitionWithDuration:(NSTimeInterval)duration
                             startRect:(CGRect)startRect
                             startEdge:(BCRectEdge)startEdge
                            completion:(void (^)())completion;



@end
