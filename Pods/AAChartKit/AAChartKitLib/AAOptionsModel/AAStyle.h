//
//  AAStyle.h
//  AAChartKit
//
//  Created by An An on 17/1/6.
//  Copyright ยฉ 2017ๅนด An An. All rights reserved.
//*************** ...... SOURCE CODE ...... ***************
//***...................................................***
//*** https://github.com/AAChartModel/AAChartKit        ***
//*** https://github.com/AAChartModel/AAChartKit-Swift  ***
//***...................................................***
//*************** ...... SOURCE CODE ...... ***************

/*
 
 * -------------------------------------------------------------------------------
 *
 * ๐ ๐ ๐ ๐  โโโ   WARM TIPS!!!   โโโ ๐ ๐ ๐ ๐
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

@interface AAStyle : NSObject

//Styles for the label. ้ป่ฎคๆฏ๏ผ{"color": "contrast", "fontSize": "11px", "fontWeight": "bold", "textOutline": "1px 1px contrast" }.
//https://api.highcharts.com/class-reference/Highcharts.CSSObject#background
AAPropStatementAndPropSetFuncStatement(copy,   AAStyle, NSString *, background)
AAPropStatementAndPropSetFuncStatement(copy,   AAStyle, NSString *, backgroundColor)
AAPropStatementAndPropSetFuncStatement(copy,   AAStyle, NSString *, border)
AAPropStatementAndPropSetFuncStatement(copy,   AAStyle, NSString *, borderRadius)
AAPropStatementAndPropSetFuncStatement(copy,   AAStyle, NSString *, color)//่ฎพ็ฝฎๆๅญ็้ข่ฒ,ๅฏไฟฎๆนไธบ #ff00ff ไปปๆ็่ฟ็งๅๅญ่ฟๅถๅญ็ฌฆไธฒ
AAPropStatementAndPropSetFuncStatement(copy,   AAStyle, NSString *, cursor)
AAPropStatementAndPropSetFuncStatement(copy,   AAStyle, NSString *, fontFamily)
AAPropStatementAndPropSetFuncStatement(copy,   AAStyle, NSString *, fontSize)//ๆๅญๅคงๅฐ
AAPropStatementAndPropSetFuncStatement(copy,   AAStyle, NSString *, fontWeight)//ๅฏ้็ๅผๆ bold, regularๅ thin ไธ็ง,ๅๅซๅฏนๅบ็ๆฏๅ?็ฒๅญไฝ,ๅธธ่งๅญไฝๅ็บค็ปๅญไฝ
AAPropStatementAndPropSetFuncStatement(strong, AAStyle, NSNumber *, height)
AAPropStatementAndPropSetFuncStatement(strong, AAStyle, NSNumber *, lineWidth)
AAPropStatementAndPropSetFuncStatement(strong, AAStyle, NSNumber *, opacity)
AAPropStatementAndPropSetFuncStatement(copy,   AAStyle, NSString *, padding)
AAPropStatementAndPropSetFuncStatement(copy,   AAStyle, NSString *, pointerEvents)
AAPropStatementAndPropSetFuncStatement(copy,   AAStyle, NSString *, position)
AAPropStatementAndPropSetFuncStatement(copy,   AAStyle, NSString *, textAlign)
AAPropStatementAndPropSetFuncStatement(copy,   AAStyle, NSString *, textDecoration)
AAPropStatementAndPropSetFuncStatement(copy,   AAStyle, NSString *, textOutline)//ๆๅญ่ฝฎๅปๆ่พน
AAPropStatementAndPropSetFuncStatement(copy,   AAStyle, NSString *, textOverflow)
AAPropStatementAndPropSetFuncStatement(copy,   AAStyle, NSString *, top)
AAPropStatementAndPropSetFuncStatement(copy,   AAStyle, NSString *, transition)
AAPropStatementAndPropSetFuncStatement(copy,   AAStyle, NSString *, whiteSpace)
AAPropStatementAndPropSetFuncStatement(strong, AAStyle, NSNumber *, width)

+ (AAStyle *)styleWithColor:(NSString *)color;

+ (AAStyle *)styleWithColor:(NSString *)color
                   fontSize:(float)fontSize;

+ (AAStyle *)styleWithColor:(NSString *)color
                   fontSize:(float)fontSize
                 fontWeight:(NSString *)fontWeight;

+ (AAStyle *)styleWithColor:(NSString *)color
                   fontSize:(float)fontSize
                 fontWeight:(NSString *)fontWeight
                textOutline:(NSString *)textOutline;

@end

