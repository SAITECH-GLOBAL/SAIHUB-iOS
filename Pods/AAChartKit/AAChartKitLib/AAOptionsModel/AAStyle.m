//
//  AAStyle.m
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

#import "AAStyle.h"

@implementation AAStyle

//Styles for the label. ้ป่ฎคๆฏ๏ผ{"color": "contrast", "fontSize": "11px", "fontWeight": "bold", "textOutline": "1px 1px contrast" }.
//https://api.highcharts.com/class-reference/Highcharts.CSSObject#background
AAPropSetFuncImplementation(AAStyle, NSString *, background)
AAPropSetFuncImplementation(AAStyle, NSString *, backgroundColor)
AAPropSetFuncImplementation(AAStyle, NSString *, border)
AAPropSetFuncImplementation(AAStyle, NSString *, borderRadius)
AAPropSetFuncImplementation(AAStyle, NSString *, color)//่ฎพ็ฝฎๆๅญ็้ข่ฒ,ๅฏไฟฎๆนไธบ #ff00ff ไปปๆ็่ฟ็งๅๅญ่ฟๅถๅญ็ฌฆไธฒ
AAPropSetFuncImplementation(AAStyle, NSString *, cursor)
AAPropSetFuncImplementation(AAStyle, NSString *, fontFamily)
AAPropSetFuncImplementation(AAStyle, NSString *, fontSize)//ๆๅญๅคงๅฐ
AAPropSetFuncImplementation(AAStyle, NSString *, fontWeight)//ๅฏ้็ๅผๆ bold, regularๅ thin ไธ็ง,ๅๅซๅฏนๅบ็ๆฏๅ?็ฒๅญไฝ,ๅธธ่งๅญไฝๅ็บค็ปๅญไฝ
AAPropSetFuncImplementation(AAStyle, NSNumber *, height)
AAPropSetFuncImplementation(AAStyle, NSNumber *, lineWidth)
AAPropSetFuncImplementation(AAStyle, NSNumber *, opacity)
AAPropSetFuncImplementation(AAStyle, NSString *, padding)
AAPropSetFuncImplementation(AAStyle, NSString *, pointerEvents)
AAPropSetFuncImplementation(AAStyle, NSString *, position)
AAPropSetFuncImplementation(AAStyle, NSString *, textAlign)
AAPropSetFuncImplementation(AAStyle, NSString *, textDecoration)
AAPropSetFuncImplementation(AAStyle, NSString *, textOutline)//ๆๅญ่ฝฎๅปๆ่พน
AAPropSetFuncImplementation(AAStyle, NSString *, textOverflow)
AAPropSetFuncImplementation(AAStyle, NSString *, top)
AAPropSetFuncImplementation(AAStyle, NSString *, transition)
AAPropSetFuncImplementation(AAStyle, NSString *, whiteSpace)
AAPropSetFuncImplementation(AAStyle, NSNumber *, width)

+ (AAStyle *)styleWithColor:(NSString *)color {
    return [self styleWithColor:color
                       fontSize:0];
}

+ (AAStyle *)styleWithColor:(NSString *)color
                   fontSize:(float)fontSize {
    return [self styleWithColor:color
                       fontSize:fontSize
                     fontWeight:nil];
}

+ (AAStyle *)styleWithColor:(NSString *)color
                   fontSize:(float)fontSize
                 fontWeight:(NSString *)fontWeight {
    return [self styleWithColor:color
                       fontSize:fontSize
                     fontWeight:fontWeight
                    textOutline:nil];
}

+ (AAStyle *)styleWithColor:(NSString *)color
                   fontSize:(float)fontSize
                 fontWeight:(NSString *)fontWeight
                textOutline:(NSString *)textOutline {
    AAStyle *aaStyle = [[AAStyle alloc]init];
    aaStyle.color = color;
    if (fontSize != 0) {
        aaStyle.fontSize = [NSString stringWithFormat:@"%fpx",fontSize];
    }
    aaStyle.fontWeight = fontWeight;
    aaStyle.textOutline = textOutline;
    return aaStyle;
}

@end
