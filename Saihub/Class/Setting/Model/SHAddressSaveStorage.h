//
//  SHAddressSaveStorage.h
//  Saihub
//
//  Created by macbook on 2022/2/28.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface SHAddressSaveStorage : NSObject
+ (instancetype) shared;
/// 数据库操作对象
@property (nonatomic,strong) RLMRealm *realm;
//获取地址列表数组
- (NSArray *)getAddressArray;
/// 删除地址
- (void)removeModel:(RLMObject *)model;
/// 添加地址
- (BOOL)addModel:(RLMObject *)model;
@end

NS_ASSUME_NONNULL_END
