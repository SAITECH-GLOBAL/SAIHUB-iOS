//
//  AALang.h
//  AAChartKitDemo
//
//  Created by AnAn on 2020/7/17.
//  Copyright ÂĐ 2020 AnAn. All rights reserved.
//*************** ...... SOURCE CODE ...... ***************
//***...................................................***
//*** https://github.com/AAChartModel/AAChartKit        ***
//*** https://github.com/AAChartModel/AAChartKit-Swift  ***
//***...................................................***
//*************** ...... SOURCE CODE ...... ***************

/*
 
 * -------------------------------------------------------------------------------
 *
 * ð ð ð ð  âââ   WARM TIPS!!!   âââ ð ð ð ð
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

@interface AALang : NSObject

AAPropStatementAndPropSetFuncStatement(copy,   AALang, NSString    *, noData) //æēĄææ°æŪ
AAPropStatementAndPropSetFuncStatement(strong, AALang, NSNumber    *, numericSymbolMagnitude) //å―éåä―įŽĶåšæ°
AAPropStatementAndPropSetFuncStatement(strong, AALang, NSArray<NSString *>    *, numericSymbols) //å―éåä―įŽĶ
AAPropStatementAndPropSetFuncStatement(copy,   AALang, NSString    *, resetZoom) // éį―ŪįžĐæūæŊäū
AAPropStatementAndPropSetFuncStatement(copy,   AALang, NSString    *, thousandsSep) // ååå·

@end

