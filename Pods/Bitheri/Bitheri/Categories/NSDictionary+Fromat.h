//
//  NSDictionary-Fromat.h
//  bitheri
//
//  Copyright 2014 http://Bither.net
//
//  Licensed under the Apache License, Version 2.0 (the "License");
//  you may not use this file except in compliance with the License.
//  You may obtain a copy of the License at
//
//    http://www.apache.org/licenses/LICENSE-2.0
//
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS,
//  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  See the License for the specific language governing permissions and
//  limitations under the License.

#import <Foundation/Foundation.h>

@interface NSDictionary (Fromat)
- (int)getIntFromDict:(NSString *)key andDefault:(int)defaultValue;

- (long)getLongFromDict:(NSString *)key andDefault:(long)defaultValue;

- (long long)getLongLongFromDict:(NSString *)key andDefault:(long long)defaultValue;

- (float)getFloatFromDict:(NSString *)key andDefault:(float)defaultValue;

- (double)getDoubleFromDict:(NSString *)key andDefault:(double)defaultValue;

- (NSString *)getStringFromDict:(NSString *)key andDefault:(NSString *)defaultValue;

- (BOOL)getBoolFromDict:(NSString *)key andDefault:(BOOL)defaultValue;

- (int)getIntFromDict:(NSString *)key;

- (long)getLongFromDict:(NSString *)key;

- (long long)getLongLongFromDict:(NSString *)key;

- (float)getFloatFromDict:(NSString *)key;

- (double)getDoubleFromDict:(NSString *)key;

- (NSString *)getStringFromDict:(NSString *)key;

- (BOOL)getBoolFromDict:(NSString *)key;

- (NSArray *)getArrayFromDict:(NSString *)key;

@end
