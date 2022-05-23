//
//  SHReceiveAddressController.m
//  Saihub
//
//  Created by 周松 on 2022/2/23.
//

#import "SHReceiveAddressController.h"
#import "JLQRCodeTool.h"

@interface SHReceiveAddressController ()

@property (nonatomic, weak) UIImageView *qrCodeImageView;

@property (nonatomic, weak) YYLabel *addressLabel;

@end

@implementation SHReceiveAddressController


- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    [self setSubviews];
}

- (void)setSubviews {
    self.titleLabel.text = GCLocalizedString(@"Receive");
    
    UIView *receiveView = [[UIView alloc]init];
    receiveView.backgroundColor = SHTheme.addressTypeCellBackColor;
    receiveView.layer.cornerRadius = 8;
    [self.view addSubview:receiveView];
    [receiveView mas_makeConstraints:^(MASConstraintMaker *make) {
        make.left.mas_equalTo(47);
        make.right.mas_equalTo(-47);
        make.top.equalTo(self.navBar.mas_bottom).offset(20);
        make.height.mas_equalTo(319 *FitWidth);
    }];
    
    UIImageView *qrCodeImageView = [[UIImageView alloc]initWithImage:[JLQRCodeTool qrcodeImageWithInfo:self.address withSize:193 *FitWidth]];
    self.qrCodeImageView = qrCodeImageView;
    [receiveView addSubview:qrCodeImageView];
    [qrCodeImageView mas_makeConstraints:^(MASConstraintMaker *make) {
        make.centerX.mas_equalTo(0);
        make.top.mas_equalTo(40);
        make.size.mas_equalTo(CGSizeMake(193 *FitWidth, 193 *FitWidth));
    }];
    
    YYLabel *addressLabel = [[YYLabel alloc]init];
    self.addressLabel = addressLabel;
    addressLabel.text = [self.address formatAddressStrLeft:6 right:6];
    addressLabel.textColor = SHTheme.agreeTipsLabelColor;
    addressLabel.font = kCustomMontserratRegularFont(14);
    addressLabel.textContainerInset = UIEdgeInsetsMake(0, 0, 0, 28);
    [receiveView addSubview:addressLabel];
    [addressLabel mas_makeConstraints:^(MASConstraintMaker *make) {
        make.centerX.equalTo(qrCodeImageView);
        make.top.equalTo(qrCodeImageView.mas_bottom).offset(24 *FitWidth);
    }];
    
    UIImageView *copyImageView = [[UIImageView alloc]initWithImage:[UIImage imageNamed:@"wallet_copyAddressButton"]];
    [addressLabel addSubview:copyImageView];
    [copyImageView mas_makeConstraints:^(MASConstraintMaker *make) {
        make.right.equalTo(addressLabel.mas_right);
        make.centerY.equalTo(addressLabel);
    }];
    
    UITapGestureRecognizer *copyTap = [[UITapGestureRecognizer alloc]initWithTarget:self action:@selector(copyAddressClick)];
    [addressLabel addGestureRecognizer:copyTap];
    
    YYLabel *refreshLabel = [[YYLabel alloc]init];
    refreshLabel.text = GCLocalizedString(@"refresh_address");
    refreshLabel.textColor = SHTheme.agreeButtonColor;
    refreshLabel.font = kCustomMontserratMediumFont(15);
    refreshLabel.textContainerInset = UIEdgeInsetsMake(0, 24, 0, 0);
    [self.view addSubview:refreshLabel];
    [refreshLabel mas_makeConstraints:^(MASConstraintMaker *make) {
        make.centerX.mas_equalTo(0);
        make.top.equalTo(receiveView.mas_bottom).offset(16);
    }];
    refreshLabel.userInteractionEnabled = YES;
    
    UITapGestureRecognizer *refreshTap = [[UITapGestureRecognizer alloc]initWithTarget:self action:@selector(refreshAddressTap)];
    [refreshLabel addGestureRecognizer:refreshTap];
    
    UIImageView *refreshImageView = [[UIImageView alloc]initWithImage:[UIImage imageNamed:@"wallet_refreshAddress"]];
    [refreshLabel addSubview:refreshImageView];
    [refreshImageView mas_makeConstraints:^(MASConstraintMaker *make) {
        make.left.mas_equalTo(0);
        make.centerY.mas_equalTo(0);
    }];
    
    JLButton *shareButton = [JLButton buttonWithType:UIButtonTypeCustom];
    shareButton.backgroundColor = SHTheme.shareBackgroundColor;
    shareButton.layer.cornerRadius = 26;
    shareButton.layer.masksToBounds = YES;
    shareButton.spacingBetweenImageAndTitle = 4;
    [shareButton setTitle:GCLocalizedString(@"Share") forState:UIControlStateNormal];
    [shareButton setTitleColor:SHTheme.agreeButtonColor forState:UIControlStateNormal];
    shareButton.titleLabel.font = kCustomMontserratMediumFont(14);
    [shareButton setImage:[UIImage imageNamed:@"wallet_shareButton"] forState:UIControlStateNormal];
    [shareButton addTarget:self action:@selector(shareButtonClick) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:shareButton];
    [shareButton mas_makeConstraints:^(MASConstraintMaker *make) {
        make.centerX.mas_equalTo(0);
        make.top.equalTo(refreshLabel.mas_bottom).offset(79);
        make.size.mas_equalTo(CGSizeMake(209, 52));
    }];
    
    if ([SHKeyStorage shared].currentWalletModel.subAddressList.count == 1 ) {
        refreshLabel.hidden = YES;
        refreshImageView.hidden = YES;
    }
}

#pragma mark -- 复制地址
- (void)copyAddressClick {
    UIPasteboard *pasteboard = [UIPasteboard generalPasteboard];
    [pasteboard setString:[SHKeyStorage shared].currentWalletModel.address];
    [MBProgressHUD showSuccess:GCLocalizedString(@"copy_address_success") toView:self.view];
}

#pragma mark -- 刷新地址
- (void)refreshAddressTap {

    NSInteger index = [SHKeyStorage shared].currentWalletModel.selectSubIndex + 1;
    
    if (index >= [SHKeyStorage shared].currentWalletModel.subAddressList.count) {
        index -= 1;
    }
    
    if (index == [SHKeyStorage shared].currentWalletModel.subAddressList.count - 1) {
        index = 0;
    }
    
    SHWalletSubAddressModel *addressModel = [[SHKeyStorage shared].currentWalletModel.subAddressList objectAtIndex:index];
    
    self.addressLabel.text = [addressModel.address formatAddressStrLeft:6 right:6];
    
    self.qrCodeImageView.image = [JLQRCodeTool qrcodeImageWithInfo:addressModel.address withSize:193 *FitWidth];
    
    [[SHKeyStorage shared] updateModelBlock:^{
        [SHKeyStorage shared].currentWalletModel.address = addressModel.address;
        [SHKeyStorage shared].currentWalletModel.selectSubIndex = index;
    }];
    
}

#pragma mark -- 分享
- (void)shareButtonClick {
    if (self.qrCodeImageView.image == nil) {
        return;
    }
    
    UIView *screenView = [[UIView alloc]initWithFrame:kSCREEN];
    screenView.backgroundColor = [UIColor whiteColor];
    [self.view addSubview:screenView];
    
    CGFloat contentW = kScreenWidth;
    CGFloat contentH = 538;
    
    // 二维码size
    CGFloat qrCodeW = 275 *FitWidth;
    
    // 底部高
    CGFloat bottomH = 99;
    
    UIView *contentView = [[UIView alloc]init];
    contentView.backgroundColor = SHTheme.appWhightColor;
    contentView.layer.cornerRadius = 16;
    [screenView addSubview:contentView];
    [contentView mas_makeConstraints:^(MASConstraintMaker *make) {
        make.centerX.mas_equalTo(0);
        make.top.mas_equalTo(126 *FitWidth + kStatusBarHeight);
        make.size.mas_equalTo(CGSizeMake(contentW, contentH));
    }];
    
    // 底部渐变view
    UIImageView *bottomView = [[UIImageView alloc]init];
    [contentView addSubview:bottomView];
    [bottomView mas_makeConstraints:^(MASConstraintMaker *make) {
        make.left.bottom.right.equalTo(contentView);
        make.height.mas_equalTo(bottomH);
    }];
    bottomView.image = [UIImage gradientImageWithBounds:CGRectMake(0, 0, contentW, bottomH) andColors:@[SHTheme.passwordInputColor,SHTheme.agreeButtonColor] andGradientType:GradientDirectionLeftToRight];
    
    CAShapeLayer *shapeLayer = [CAShapeLayer layer];
    shapeLayer.path = [UIBezierPath bezierPathWithRoundedRect:CGRectMake(0, 0, contentW, bottomH) byRoundingCorners:UIRectCornerBottomLeft | UIRectCornerBottomRight cornerRadii:CGSizeMake(16, 16)].CGPath;
    bottomView.layer.mask = shapeLayer;
    
    UIView *topView = [[UIView alloc]init];
    topView.backgroundColor = [UIColor whiteColor];
    topView.layer.cornerRadius = 16;
    [contentView addSubview:topView];
    [topView mas_makeConstraints:^(MASConstraintMaker *make) {
        make.width.equalTo(contentView);
        make.height.mas_equalTo(contentH - bottomH + 16);
        make.top.centerX.mas_equalTo(0);
    }];
    
    UILabel *titleLabel = [[UILabel alloc]init];
    titleLabel.text = @"BTC";
    titleLabel.textColor = [UIColor blackColor];
    titleLabel.font = kCustomMontserratMediumFont(18);
    [topView addSubview:titleLabel];
    [titleLabel mas_makeConstraints:^(MASConstraintMaker *make) {
        make.centerX.mas_equalTo(0);
        make.top.mas_equalTo(20);
    }];
    
    UIView *qrCodeBorderView = [[UIView alloc]init];
    qrCodeBorderView.backgroundColor = SHTheme.addressTypeCellBackColor;
    [contentView addSubview:qrCodeBorderView];
    qrCodeBorderView.layer.cornerRadius = 16;
    [qrCodeBorderView mas_makeConstraints:^(MASConstraintMaker *make) {
        make.size.mas_equalTo(CGSizeMake(qrCodeW, qrCodeW));
        make.centerX.equalTo(contentView);
        make.top.mas_equalTo(54);
    }];
    
    // 地址二维码
    UIImageView *qrCodeImageView = [[UIImageView alloc]initWithImage:self.qrCodeImageView.image];
    [qrCodeBorderView addSubview:qrCodeImageView];
    [qrCodeImageView mas_makeConstraints:^(MASConstraintMaker *make) {
        make.edges.mas_equalTo(UIEdgeInsetsMake(12, 12, 12, 12));
    }];
    
    UILabel *addressLabel = [[UILabel alloc]init];
    addressLabel.text = [SHKeyStorage shared].currentWalletModel.address;
    addressLabel.textColor = SHTheme.agreeTipsLabelColor;
    addressLabel.font = kCustomMontserratRegularFont(12);
    addressLabel.textAlignment = NSTextAlignmentCenter;
    addressLabel.numberOfLines = 0;
    [topView addSubview:addressLabel];
    [addressLabel mas_makeConstraints:^(MASConstraintMaker *make) {
        make.left.mas_equalTo(25 *FitWidth);
        make.right.mas_equalTo(-25 *FitWidth);
        make.top.equalTo(qrCodeBorderView.mas_bottom).offset(16);
    }];

    // icon
    UIImageView *iconImageView = [[UIImageView alloc]initWithImage:[UIImage imageNamed:@"appIcon_whiteImage"]];
    [bottomView addSubview:iconImageView];
    [iconImageView mas_makeConstraints:^(MASConstraintMaker *make) {
        make.left.mas_equalTo(20 *FitWidth);
        make.top.equalTo(bottomView.mas_top).offset(32);
    }];
    
    // 网址
    UILabel *websiteLabel = [[UILabel alloc]init];
    websiteLabel.text = @"https://sai.tech";
    websiteLabel.textColor = SHTheme.appWhightColor;
    websiteLabel.font = kCustomMontserratRegularFont(12);
    [bottomView addSubview:websiteLabel];
    [websiteLabel mas_makeConstraints:^(MASConstraintMaker *make) {
        make.left.equalTo(iconImageView.mas_left);
        make.bottom.equalTo(bottomView.mas_bottom).offset(-21);
    }];
    
    // 下载二维码
    UIView *downloadView = [[UIView alloc]init];
    [bottomView addSubview:downloadView];
    downloadView.layer.cornerRadius = 4;
    downloadView.backgroundColor = [UIColor whiteColor];
    [downloadView mas_makeConstraints:^(MASConstraintMaker *make) {
        make.right.mas_equalTo(-20 *FitWidth);
        make.bottom.mas_equalTo(-20);
        make.size.mas_equalTo(CGSizeMake(46, 46));
    }];
    
    UIImageView *downloadImageView = [[UIImageView alloc]init];
    [downloadView addSubview:downloadImageView];
    [downloadImageView mas_makeConstraints:^(MASConstraintMaker *make) {
        make.edges.mas_equalTo(UIEdgeInsetsMake(3, 3, 3, 3));
    }];
    downloadImageView.image = [JLQRCodeTool qrcodeImageWithInfo:@"https://sai.tech" withSize:40];
    
    [self.view layoutIfNeeded];
    
    UIGraphicsBeginImageContextWithOptions(CGSizeMake(kScreenWidth, contentView.height),YES,[UIScreen mainScreen].scale);
    [contentView.layer renderInContext:UIGraphicsGetCurrentContext()];
    UIImage *image = UIGraphicsGetImageFromCurrentImageContext();
    UIGraphicsEndImageContext();
    
    screenView.hidden = YES;
    [screenView removeFromSuperview];
    
    UIActivityViewController *activityVC = [[UIActivityViewController alloc]initWithActivityItems:@[image] applicationActivities:nil];
    
    UIActivityViewControllerCompletionWithItemsHandler myBlock = ^(NSString *activityType, BOOL completed, NSArray *returnedItems, NSError *activityError){
        if (completed == YES) {
            if ([activityType isEqualToString:@"com.apple.UIKit.activity.CopyToPasteboard"]) {
                [MBProgressHUD showSuccess:GCLocalizedString(@"copy_success") toView:self.view];
            } else {
                [MBProgressHUD showSuccess:GCLocalizedString(@"share_success") toView:self.view];
            }
        }
    };
    activityVC.completionWithItemsHandler = myBlock;
    activityVC.excludedActivityTypes = nil;
    [self presentViewController:activityVC animated:YES completion:nil];
    
}

@end
