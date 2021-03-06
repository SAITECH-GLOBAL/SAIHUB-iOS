//
//  AAColumnrange.h
//  AAChartKitDemo
//
//  Created by An An on 2021/7/20.
//  Copyright Β© 2021 An An. All rights reserved.
//*************** ...... SOURCE CODE ...... ***************
//***...................................................***
//*** https://github.com/AAChartModel/AAChartKit        ***
//*** https://github.com/AAChartModel/AAChartKit-Swift  ***
//***...................................................***
//*************** ...... SOURCE CODE ...... ***************

/*
 
 * -------------------------------------------------------------------------------
 *
 * π π π π  βββ   WARM TIPS!!!   βββ π π π π
 *
 * Please contact me on GitHub,if there are any problems encountered in use.
 * GitHub Issues : https://github.com/AAChartModel/AAChartKit/issues
 * -------------------------------------------------------------------------------
 * And if you want to contribute for this project, please contact me as well
 * GitHub        : https://github.com/AAChartModel
 * StackOverflow : https://stackoverflow.com/users/12302132/codeforu
 * JianShu       : https://www.jianshu.com/u/f1e6753d4254
 * SegmentFault  : https://segmentfault.com/u/huanghunbieguan
 *
 * -------------------------------------------------------------------------------
 
 */

#import <Foundation/Foundation.h>

@class AADataLabels;

@interface AAColumnrange : NSObject

AAPropStatementAndPropSetFuncStatement(strong, AAColumnrange, NSNumber *,     borderRadius)
AAPropStatementAndPropSetFuncStatement(strong, AAColumnrange, NSNumber *,     borderWidth)
AAPropStatementAndPropSetFuncStatement(strong, AAColumnrange, AADataLabels *, dataLabels)
AAPropStatementAndPropSetFuncStatement(strong, AAColumnrange, NSNumber *,     groupPadding) //Padding between each value groups, in x axis units. defaultοΌ0.2.
AAPropStatementAndPropSetFuncStatement(assign, AAColumnrange, BOOL,           grouping) //Whether to group non-stacked columns or to let them render independent of each other. Non-grouped columns will be laid out individually and overlap each other. defaultοΌtrue.
AAPropStatementAndPropSetFuncStatement(strong, AAColumnrange, NSNumber *,     pointPadding) //Padding between each column or bar, in x axis units. defaultοΌ0.1.
AAPropStatementAndPropSetFuncStatement(strong, AAColumnrange, NSNumber *,     pointPlacement) //Padding between each column or bar, in x axis units. defaultοΌ0.1.


@end

