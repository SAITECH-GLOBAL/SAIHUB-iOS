//
//  BTKey.h
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
//
//  Copyright (c) 2013-2014 Aaron Voisine <voisine@gmail.com>
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in
//  all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//  THE SOFTWARE.

#import <Foundation/Foundation.h>

typedef struct _BRPubKey {
    uint8_t u8[33];
} BRPubKey;

#define SALT_LENGTH              8
#define IS_COMPRESSED_FLAG       1
#define IS_FROMXRANDOM_FLAG      2

@interface BTKey : NSObject

@property(nonatomic, copy) NSString *privateKey;
@property(nonatomic, copy) NSData *publicKey;
@property(nonatomic, readonly) NSString *address;
@property(nonatomic, readonly) NSData *hash160;
@property BOOL compressed;
@property BOOL isFromXRandom;

+ (instancetype)keyWithPrivateKey:(NSString *)privateKey;

+ (instancetype)keyWithSecret:(NSData *)secret compressed:(BOOL)compressed;

+ (instancetype)keyWithPublicKey:(NSData *)publicKey;

- (instancetype)initWithPrivateKey:(NSString *)privateKey;

- (instancetype)initWithSecret:(NSData *)secret compressed:(BOOL)compressed;

- (instancetype)initWithPublicKey:(NSData *)publicKey;

- (NSData *)sign:(NSData *)d;

- (BOOL)verify:(NSData *)d signature:(NSData *)sig;

- (uint8_t)getKeyFlag;

+ (NSData *)getRFromSignature:(NSData *)sig;

- (NSString *)signMessage:(NSString *)message;

- (NSData *)signHash:(NSData *)hash;

- (BOOL)verifyMessage:(NSString *)message andSignatureBase64:(NSString *)signatureBase64;

+ (BTKey *)signedMessageToKey:(NSString *)message andSignatureBase64:(NSString *)signatureBase64;

- (NSString *)toSegwitAddress;

- (NSData *)getRedeemScript;
@end

