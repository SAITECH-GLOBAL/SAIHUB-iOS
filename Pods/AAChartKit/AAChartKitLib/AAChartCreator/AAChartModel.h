//
//  AAChartModel.h
//  AAChartKit
//
//  Created by An An on 17/1/20.
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
#import "AASeriesElement.h"
#import "AAPlotLinesElement.h"
@class AAStyle, AALineStyle, AACrosshair, AAScrollablePlotArea;

typedef NS_ENUM(NSInteger,AAChartAnimation) {
    AAChartAnimationLinear = 0,
    AAChartAnimationEaseInQuad,
    AAChartAnimationEaseOutQuad,
    AAChartAnimationEaseInOutQuad,
    AAChartAnimationEaseInCubic,
    AAChartAnimationEaseOutCubic,
    AAChartAnimationEaseInOutCubic,
    AAChartAnimationEaseInQuart,
    AAChartAnimationEaseOutQuart,
    AAChartAnimationEaseInOutQuart,
    AAChartAnimationEaseInQuint,
    AAChartAnimationEaseOutQuint,
    AAChartAnimationEaseInOutQuint,
    AAChartAnimationEaseInSine,
    AAChartAnimationEaseOutSine,
    AAChartAnimationEaseInOutSine,
    AAChartAnimationEaseInExpo,
    AAChartAnimationEaseOutExpo,
    AAChartAnimationEaseInOutExpo,
    AAChartAnimationEaseInCirc,
    AAChartAnimationEaseOutCirc,
    AAChartAnimationEaseInOutCirc,
    AAChartAnimationEaseOutBounce,
    AAChartAnimationEaseInBack,
    AAChartAnimationEaseOutBack,
    AAChartAnimationEaseInOutBack,
    AAChartAnimationElastic,
    AAChartAnimationSwingFromTo,
    AAChartAnimationSwingFrom,
    AAChartAnimationSwingTo,
    AAChartAnimationBounce,
    AAChartAnimationBouncePast,
    AAChartAnimationEaseFromTo,
    AAChartAnimationEaseFrom,
    AAChartAnimationEaseTo,
};

typedef NSString *AAChartType;
typedef NSString *AAChartLayoutType;
typedef NSString *AAChartAlignType;
typedef NSString *AAChartVerticalAlignType;
typedef NSString *AAChartZoomType;
typedef NSString *AAChartStackingType;
typedef NSString *AAChartSymbolType;
typedef NSString *AAChartSymbolStyleType;
typedef NSString *AAChartFontWeightType;
typedef NSString *AAChartLineDashStyleType;

AACHARTKIT_EXTERN AAChartType const AAChartTypeColumn;
AACHARTKIT_EXTERN AAChartType const AAChartTypeBar;
AACHARTKIT_EXTERN AAChartType const AAChartTypeArea;
AACHARTKIT_EXTERN AAChartType const AAChartTypeAreaspline;
AACHARTKIT_EXTERN AAChartType const AAChartTypeLine;
AACHARTKIT_EXTERN AAChartType const AAChartTypeSpline;
AACHARTKIT_EXTERN AAChartType const AAChartTypeScatter;
AACHARTKIT_EXTERN AAChartType const AAChartTypePie;
AACHARTKIT_EXTERN AAChartType const AAChartTypeBubble;
AACHARTKIT_EXTERN AAChartType const AAChartTypePyramid;
AACHARTKIT_EXTERN AAChartType const AAChartTypeFunnel;
AACHARTKIT_EXTERN AAChartType const AAChartTypeColumnrange;
AACHARTKIT_EXTERN AAChartType const AAChartTypeArearange;
AACHARTKIT_EXTERN AAChartType const AAChartTypeAreasplinerange;
AACHARTKIT_EXTERN AAChartType const AAChartTypeBoxplot;
AACHARTKIT_EXTERN AAChartType const AAChartTypeWaterfall;
AACHARTKIT_EXTERN AAChartType const AAChartTypePolygon;
AACHARTKIT_EXTERN AAChartType const AAChartTypeErrorbar;
AACHARTKIT_EXTERN AAChartType const AAChartTypeGauge;

AACHARTKIT_EXTERN AAChartLayoutType const AAChartLayoutTypeHorizontal;
AACHARTKIT_EXTERN AAChartLayoutType const AAChartLayoutTypeVertical;

AACHARTKIT_EXTERN AAChartAlignType const AAChartAlignTypeLeft;
AACHARTKIT_EXTERN AAChartAlignType const AAChartAlignTypeCenter;
AACHARTKIT_EXTERN AAChartAlignType const AAChartAlignTypeRight;

AACHARTKIT_EXTERN AAChartVerticalAlignType const AAChartVerticalAlignTypeTop;
AACHARTKIT_EXTERN AAChartVerticalAlignType const AAChartVerticalAlignTypeMiddle;
AACHARTKIT_EXTERN AAChartVerticalAlignType const AAChartVerticalAlignTypeBottom;

AACHARTKIT_EXTERN AAChartZoomType const AAChartZoomTypeNone;
AACHARTKIT_EXTERN AAChartZoomType const AAChartZoomTypeX;
AACHARTKIT_EXTERN AAChartZoomType const AAChartZoomTypeY;
AACHARTKIT_EXTERN AAChartZoomType const AAChartZoomTypeXY;

AACHARTKIT_EXTERN AAChartStackingType const AAChartStackingTypeFalse;
AACHARTKIT_EXTERN AAChartStackingType const AAChartStackingTypeNormal;
AACHARTKIT_EXTERN AAChartStackingType const AAChartStackingTypePercent;

AACHARTKIT_EXTERN AAChartSymbolType const AAChartSymbolTypeCircle;
AACHARTKIT_EXTERN AAChartSymbolType const AAChartSymbolTypeSquare;
AACHARTKIT_EXTERN AAChartSymbolType const AAChartSymbolTypeDiamond;
AACHARTKIT_EXTERN AAChartSymbolType const AAChartSymbolTypeTriangle;
AACHARTKIT_EXTERN AAChartSymbolType const AAChartSymbolTypeTriangle_down;

AACHARTKIT_EXTERN AAChartSymbolStyleType const AAChartSymbolStyleTypeDefault;
AACHARTKIT_EXTERN AAChartSymbolStyleType const AAChartSymbolStyleTypeInnerBlank;
AACHARTKIT_EXTERN AAChartSymbolStyleType const AAChartSymbolStyleTypeBorderBlank;

AACHARTKIT_EXTERN AAChartFontWeightType const AAChartFontWeightTypeThin;
AACHARTKIT_EXTERN AAChartFontWeightType const AAChartFontWeightTypeRegular;
AACHARTKIT_EXTERN AAChartFontWeightType const AAChartFontWeightTypeBold;

AACHARTKIT_EXTERN AAChartLineDashStyleType const AAChartLineDashStyleTypeSolid;
AACHARTKIT_EXTERN AAChartLineDashStyleType const AAChartLineDashStyleTypeShortDash;
AACHARTKIT_EXTERN AAChartLineDashStyleType const AAChartLineDashStyleTypeShortDot;
AACHARTKIT_EXTERN AAChartLineDashStyleType const AAChartLineDashStyleTypeShortDashDot;
AACHARTKIT_EXTERN AAChartLineDashStyleType const AAChartLineDashStyleTypeShortDashDotDot;
AACHARTKIT_EXTERN AAChartLineDashStyleType const AAChartLineDashStyleTypeDot;
AACHARTKIT_EXTERN AAChartLineDashStyleType const AAChartLineDashStyleTypeDash;
AACHARTKIT_EXTERN AAChartLineDashStyleType const AAChartLineDashStyleTypeLongDash;
AACHARTKIT_EXTERN AAChartLineDashStyleType const AAChartLineDashStyleTypeDashDot;
AACHARTKIT_EXTERN AAChartLineDashStyleType const AAChartLineDashStyleTypeLongDashDot;
AACHARTKIT_EXTERN AAChartLineDashStyleType const AAChartLineDashStyleTypeLongDashDotDot;

@interface AAChartModel : NSObject

AAPropStatementAndPropSetFuncStatement(copy,   AAChartModel, NSString *, title) //ๆ?้ขๅๅฎน
AAPropStatementAndPropSetFuncStatement(strong, AAChartModel, AAStyle  *, titleStyle) //ๆ?้ขๆๅญๆ?ทๅผ

AAPropStatementAndPropSetFuncStatement(copy,   AAChartModel, NSString *, subtitle) //ๅฏๆ?้ขๅๅฎน
AAPropStatementAndPropSetFuncStatement(strong, AAChartModel, AAStyle  *, subtitleStyle) //ๅฏๆ?้ขๆๅญๆ?ทๅผ
AAPropStatementAndPropSetFuncStatement(copy,   AAChartModel, AAChartAlignType, subtitleAlign) //ๅพ่กจๅฏๆ?้ขๆๆฌๆฐดๅนณๅฏน้ฝๆนๅผใๅฏ้็ๅผๆ โleftโ๏ผโcenterโๅโrightโใ ้ป่ฎคๆฏ๏ผcenter.

AAPropStatementAndPropSetFuncStatement(copy,   AAChartModel, NSString *, backgroundColor) //ๅพ่กจ่ๆฏ่ฒ(ๅฟ้กปไธบๅๅญ่ฟๅถ็้ข่ฒ่ฒๅผๅฆ็บข่ฒ"#FF0000")
AAPropStatementAndPropSetFuncStatement(strong, AAChartModel, NSArray  *, colorsTheme) //ๅพ่กจไธป้ข้ข่ฒๆฐ็ป
AAPropStatementAndPropSetFuncStatement(strong, AAChartModel, NSArray     <NSString *>*, categories) //x่ฝดๅๆ?ๆฏไธช็นๅฏนๅบ็ๅ็งฐ(ๆณจๆ:่ฟไธชไธๆฏ็จๆฅ่ฎพ็ฝฎ X ่ฝด็ๅผ,ไปไปๆฏ็จไบ่ฎพ็ฝฎ X ่ฝดๆๅญๅๅฎน็่ๅทฒ)
AAPropStatementAndPropSetFuncStatement(strong, AAChartModel, NSArray  *, series) //ๅพ่กจ็ๆฐๆฎๅๅๅฎน

AAPropStatementAndPropSetFuncStatement(copy,   AAChartModel, AAChartType,              chartType) //ๅพ่กจ็ฑปๅ
AAPropStatementAndPropSetFuncStatement(copy,   AAChartModel, AAChartStackingType,      stacking) //ๅ?็งฏๆ?ทๅผ
AAPropStatementAndPropSetFuncStatement(copy,   AAChartModel, AAChartSymbolType,        markerSymbol) //ๆ็บฟๆฒ็บฟ่ฟๆฅ็น็็ฑปๅ๏ผ"circle", "square", "diamond", "triangle","triangle-down"๏ผ้ป่ฎคๆฏ"circle"
AAPropStatementAndPropSetFuncStatement(assign, AAChartModel, AAChartSymbolStyleType,   markerSymbolStyle)
AAPropStatementAndPropSetFuncStatement(copy,   AAChartModel, AAChartZoomType,          zoomType) //็ผฉๆพ็ฑปๅ AAChartZoomTypeX ่กจ็คบๅฏๆฒฟ็ x ่ฝด่ฟ่กๆๅฟ็ผฉๆพ
AAPropStatementAndPropSetFuncStatement(assign, AAChartModel, AAChartAnimation,         animationType) //่ฎพ็ฝฎๅพ่กจ็ๆธฒๆๅจ็ป็ฑปๅ
AAPropStatementAndPropSetFuncStatement(strong, AAChartModel, NSNumber *, animationDuration) //่ฎพ็ฝฎๅพ่กจ็ๆธฒๆๅจ็ปๆถ้ฟ(ๅจ็ปๅไฝไธบๆฏซ็ง)
AAPropStatementAndPropSetFuncStatement(assign, AAChartModel, BOOL,       inverted) //x ่ฝดๆฏๅฆๅ็ด,้ป่ฎคไธบๅฆ
AAPropStatementAndPropSetFuncStatement(assign, AAChartModel, BOOL,       polar) //ๆฏๅฆๆๅๅพๅฝข(ๅไธบ้ท่พพๅพ),้ป่ฎคไธบๅฆ
AAPropStatementAndPropSetFuncStatement(strong, AAChartModel, NSArray  *, margin) //// ๅพ่กจๅค่พน็ผๅ็ปๅพๅบๅไน้ด็่พน่ทใ ๆฐ็ปไธญ็ๆฐๅญๅๅซ่กจ็คบ้กถ้จ๏ผๅณไพง๏ผๅบ้จๅๅทฆไพง ([๐,๐,๐,๐])ใ ไนๅฏไปฅไฝฟ็จ AAChart ๅฏน่ฑก็ marginTop๏ผmarginRight๏ผmarginBottom ๅ marginLeft ๆฅ่ฎพ็ฝฎๆไธไธชๆนๅ็่พน่ทใ้ป่ฎคๅผไธบ[null]

AAPropStatementAndPropSetFuncStatement(assign, AAChartModel, BOOL,       dataLabelsEnabled) //ๆฏๅฆๆพ็คบๆฐๆฎ,้ป่ฎคไธบๅฆ
AAPropStatementAndPropSetFuncStatement(strong, AAChartModel, AAStyle  *, dataLabelsStyle) //dataLabelsๆๅญๆ?ทๅผ

AAPropStatementAndPropSetFuncStatement(assign, AAChartModel, BOOL,       xAxisVisible) //x ่ฝดๆฏๅฆๅฏ่ง(้ป่ฎคๅฏ่ง)
AAPropStatementAndPropSetFuncStatement(assign, AAChartModel, BOOL,       xAxisReversed) // x ่ฝด็ฟป่ฝฌ,้ป่ฎคไธบๅฆ
AAPropStatementAndPropSetFuncStatement(assign, AAChartModel, BOOL,       xAxisLabelsEnabled) //x ่ฝดๆฏๅฆๆพ็คบๆๅญ
AAPropStatementAndPropSetFuncStatement(strong, AAChartModel, AAStyle  *, xAxisLabelsStyle) //x ่ฝดๆๅญๆ?ทๅผ
AAPropStatementAndPropSetFuncStatement(strong, AAChartModel, NSNumber *, xAxisTickInterval) //x่ฝดๅปๅบฆ็น้ด้ๆฐ(่ฎพ็ฝฎๆฏ้ๅ?ไธช็นๆพ็คบไธไธช X่ฝด็ๅๅฎน)
AAPropStatementAndPropSetFuncStatement(strong, AAChartModel, AALineStyle *, xAxisGridLineStyle) //x ่ฝด็ฝๆ?ผ็บฟ็ๆ?ทๅผ
AAPropStatementAndPropSetFuncStatement(strong, AAChartModel, AACrosshair *, xAxisCrosshair)

AAPropStatementAndPropSetFuncStatement(assign, AAChartModel, BOOL,       yAxisVisible) //y ่ฝดๆฏๅฆๅฏ่ง(้ป่ฎคๅฏ่ง)
AAPropStatementAndPropSetFuncStatement(assign, AAChartModel, BOOL,       yAxisReversed) //y ่ฝด็ฟป่ฝฌ,้ป่ฎคไธบๅฆ
AAPropStatementAndPropSetFuncStatement(assign, AAChartModel, BOOL,       yAxisLabelsEnabled) //y ่ฝดๆฏๅฆๆพ็คบๆๅญ
AAPropStatementAndPropSetFuncStatement(strong, AAChartModel, AAStyle  *, yAxisLabelsStyle) // y ่ฝดๆๅญๆ?ทๅผ
AAPropStatementAndPropSetFuncStatement(copy,   AAChartModel, NSString *, yAxisTitle) //y ่ฝดๆ?้ข
AAPropStatementAndPropSetFuncStatement(strong, AAChartModel, NSNumber *, yAxisLineWidth) //y y-axis line width
AAPropStatementAndPropSetFuncStatement(assign, AAChartModel, BOOL,       yAxisAllowDecimals) //ๆฏๅฆๅ่ฎธ y ่ฝดๆพ็คบๅฐๆฐ
AAPropStatementAndPropSetFuncStatement(strong, AAChartModel, NSArray  *, yAxisPlotLines) //y ่ฝดๆ?็คบ็บฟ๐งถ็้็ฝฎ
AAPropStatementAndPropSetFuncStatement(strong, AAChartModel, NSNumber *, yAxisMax) //y ่ฝดๆๅคงๅผ
AAPropStatementAndPropSetFuncStatement(strong, AAChartModel, NSNumber *, yAxisMin) //y ่ฝดๆๅฐๅผ๏ผ่ฎพ็ฝฎไธบ0ๅฐฑไธไผๆ่ดๆฐ๏ผ
AAPropStatementAndPropSetFuncStatement(strong, AAChartModel, NSNumber *, yAxisTickInterval)
AAPropStatementAndPropSetFuncStatement(strong, AAChartModel, NSArray  *, yAxisTickPositions) //่ชๅฎไน y ่ฝดๅๆ?๏ผๅฆ๏ผ[@(0), @(25), @(50), @(75) , (100)]๏ผ
AAPropStatementAndPropSetFuncStatement(strong, AAChartModel, AALineStyle *, yAxisGridLineStyle) //y ่ฝด็ฝๆ?ผ็บฟ็ๆ?ทๅผ
AAPropStatementAndPropSetFuncStatement(strong, AAChartModel, AACrosshair *, yAxisCrosshair)

AAPropStatementAndPropSetFuncStatement(assign, AAChartModel, BOOL,       tooltipEnabled) //ๆฏๅฆๆพ็คบๆตฎๅจๆ็คบๆก(้ป่ฎคๆพ็คบ)
AAPropStatementAndPropSetFuncStatement(assign, AAChartModel, BOOL,       tooltipShared)//ๆฏๅฆๅค็ปๆฐๆฎๅฑไบซไธไธชๆตฎๅจๆ็คบๆก
AAPropStatementAndPropSetFuncStatement(copy,   AAChartModel, NSString *, tooltipValueSuffix) //ๆตฎๅจๆ็คบๆกๅไฝๅ็ผ

AAPropStatementAndPropSetFuncStatement(assign, AAChartModel, BOOL,       connectNulls) //่ฎพ็ฝฎๆ็บฟๆฏๅฆๆญ็น้่ฟ(ๆฏๅฆ่ฟๆฅ็ฉบๅผ็น)
AAPropStatementAndPropSetFuncStatement(assign, AAChartModel, BOOL,       legendEnabled) //ๆฏๅฆๆพ็คบๅพไพ lengend(ๅพ่กจๅบ้จๅฏ็นๆ็ๅ็นๅๆๅญ)
AAPropStatementAndPropSetFuncStatement(strong, AAChartModel, NSNumber *, borderRadius) //ๆฑ็ถๅพ้ฟๆกๅพๅคด้จๅ่งๅๅพ(ๅฏ็จไบ่ฎพ็ฝฎๅคด้จ็ๅฝข็ถ,ไปๅฏนๆกๅฝขๅพ,ๆฑ็ถๅพๆๆ)
AAPropStatementAndPropSetFuncStatement(strong, AAChartModel, NSNumber *, markerRadius) //ๆ็บฟ่ฟๆฅ็น็ๅๅพ้ฟๅบฆ
AAPropStatementAndPropSetFuncStatement(strong, AAChartModel, AAScrollablePlotArea *, scrollablePlotArea)

@end


@interface AAChartModel(Unavailable)

@property (nonatomic, strong) NSNumber * titleFontSize AAChartKitUnavailable("`titleFontSize` was removed, please use titleStyle instead of it");
- (AAChartModel * (^) (NSNumber * titleFontSize))titleFontSizeSet AAChartKitUnavailable("`titleFontSizeSet` was removed, please use titleStyleSet instead of it");

@property (nonatomic, strong) NSString * titleFontColor AAChartKitUnavailable("`titleFontColor` was removed, please use titleStyle instead of it");
- (AAChartModel * (^) (NSString * titleFontColor))titleFontColorSet AAChartKitUnavailable("`titleFontColorSet` was removed, please use titleStyleSet instead of it");

@property (nonatomic, strong) NSString * titleFontWeight AAChartKitUnavailable("`titleFontWeight` was removed, please use titleStyle instead of it");
- (AAChartModel * (^) (NSString * titleFontWeight))titleFontWeightSet AAChartKitUnavailable("`titleFontWeightSet` was removed, please use titleStyleSet instead of it");



@property (nonatomic, strong) NSNumber * subtitleFontSize AAChartKitUnavailable("`subtitleFontSize` was removed, please use subtitleStyle instead of it");
- (AAChartModel * (^) (NSNumber * subtitleFontSize))subtitleFontSizeSet AAChartKitUnavailable("`subtitleFontSizeSet` was removed, please use subtitleStyleSet instead of it");

@property (nonatomic, strong) NSString * subtitleFontColor AAChartKitUnavailable("`subtitleFontColor` was removed, please use subtitleStyle instead of it");
- (AAChartModel * (^) (NSString * subtitleFontColor))subtitleFontColorSet AAChartKitUnavailable("`subtitleFontColorSet` was removed, please use subtitleStyleSet instead of it");

@property (nonatomic, strong) NSString * subtitleFontWeight AAChartKitUnavailable("`subtitleFontWeight` was removed, please use subtitleStyle instead of it");
- (AAChartModel * (^) (NSString * subtitleFontWeight))subtitleFontWeightSet AAChartKitUnavailable("`subtitleFontWeightSet` was removed, please use subtitleStyleSet instead of it");



@property (nonatomic, strong) NSNumber * dataLabelsFontSize AAChartKitUnavailable("`dataLabelsFontSize` was removed, please use dataLabelsStyle instead of it");
- (AAChartModel * (^) (NSNumber * dataLabelsFontSize))dataLabelsFontSizeSet AAChartKitUnavailable("`dataLabelsFontSizeSet` was removed, please use dataLabelsStyleSet instead of it");

@property (nonatomic, strong) NSString * dataLabelsFontColor AAChartKitUnavailable("`dataLabelsFontColor` was removed, please use dataLabelsStyle instead of it");
- (AAChartModel * (^) (NSString * dataLabelsFontColor))dataLabelsFontColorSet AAChartKitUnavailable("`dataLabelsFontColorSet` was removed, please use dataLabelsStyleSet instead of it");

@property (nonatomic, strong) NSString * dataLabelsFontWeight AAChartKitUnavailable("`dataLabelsFontWeight` was removed, please use dataLabelsStyle instead of it");
- (AAChartModel * (^) (NSString * dataLabelsFontWeight))dataLabelsFontWeightSet AAChartKitUnavailable("`dataLabelsFontWeightSet` was removed, please use dataLabelsStyleSet instead of it");



@property (nonatomic, strong) NSNumber * xAxisLabelsFontSize AAChartKitUnavailable("`xAxisLabelsFontSize` was removed, please use xAxisLabelsStyle instead of it");
- (AAChartModel * (^) (NSNumber * xAxisLabelsFontSize))xAxisLabelsFontSizeSet AAChartKitUnavailable("`xAxisLabelsFontSizeSet` was removed, please use xAxisLabelsStyleSet instead of it");

@property (nonatomic, strong) NSString * xAxisLabelsFontColor AAChartKitUnavailable("`xAxisLabelsFontColor` was removed, please use xAxisLabelsStyle instead of it");
- (AAChartModel * (^) (NSString * xAxisLabelsFontColor))xAxisLabelsFontColorSet AAChartKitUnavailable("`xAxisLabelsFontColorSet` was removed, please use xAxisLabelsStyleSet instead of it");

@property (nonatomic, strong) NSString * xAxisLabelsFontWeight AAChartKitUnavailable("`xAxisLabelsFontWeight` was removed, please use xAxisLabelsStyle instead of it");
- (AAChartModel * (^) (NSString * xAxisLabelsFontWeight))xAxisLabelsFontWeightSet AAChartKitUnavailable("`xAxisLabelsFontWeightSet` was removed, please use xAxisLabelsStyleSet instead of it");



@property (nonatomic, strong) NSNumber * yAxisLabelsFontSize AAChartKitUnavailable("`yAxisLabelsFontSize` was removed, please use yAxisLabelsStyle instead of it");
- (AAChartModel * (^) (NSNumber * yAxisLabelsFontSize))yAxisLabelsFontSizeSet AAChartKitUnavailable("`yAxisLabelsFontSizeSet` was removed, please use yAxisLabelsStyleSet instead of it");

@property (nonatomic, strong) NSString * yAxisLabelsFontColor AAChartKitUnavailable("`yAxisLabelsFontColor` was removed, please use yAxisLabelsStyle instead of it");
- (AAChartModel * (^) (NSString * yAxisLabelsFontColor))yAxisLabelsFontColorSet AAChartKitUnavailable("`yAxisLabelsFontColorSet` was removed, please use yAxisLabelsStyleSet instead of it");

@property (nonatomic, strong) NSString * yAxisLabelsFontWeight AAChartKitUnavailable("`yAxisLabelsFontWeight` was removed, please use yAxisLabelsStyle instead of it");
- (AAChartModel * (^) (NSString * yAxisLabelsFontWeight))yAxisLabelsFontWeightSet AAChartKitUnavailable("`yAxisLabelsFontWeightSet` was removed, please use yAxisLabelsStyleSet instead of it");

@end
