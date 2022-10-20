//
//  Objc2020.h
//  Objc2020 1.0
//
//  Created by MeterWhite on 2020/6/25.
//  Copyright © 2020 Meterwhite. All rights reserved.
//

#ifndef Objc2020
#define Objc2020

#import <Foundation/Foundation.h>
#import "Objc2020Connect.h"

#if TARGET_OS_IPHONE || TARGET_OS_TV

#import <UIKit/UIKit.h>

#define OPPImage UIImage

#elif TARGET_OS_MAC

#import <AppKit/AppKit.h>

#define OPPImage NSImage

#endif

#pragma mark - LET do something
/// 🌟
/// LET_NEW(NSObject, x);
/// LET_NEW(NSObject, x, y, z, ...);
#define LET_NEW(T, ...) CORE_CONNECT_FOREACH_CXT(__CODEPP_FOREACH_NEW_OBJ,;,T,__VA_ARGS__)
/// 🌟
/// let swift = expresion
/// LET_VAR(x, ⁼, expresion) => typeof(expresion) x = expresion
#define LET_VAR(var, ⁼, ...)  typeof((__VA_ARGS__)) var = __VA_ARGS__
/// LET_AS(arrary, NSString) => nil
/// LET_AS(str, NSString) => str
#define LET_AS(obj, T) ((typeof(T *))([obj isKindOfClass:[T class]] ? (obj) : ((void *)0)))
/// LET_TOGGLE(a) => (a = !a)
#define LET_TOGGLE(__VA_ARGS__) __VA_ARGS__ = !__VA_ARGS__
/// 🌟
/// LET_KVC(obj, key) => valueForKey
/// LET_KVC(obj, value, key) => setValue:forKey:
#define LET_KVC(dst,...) \
CORE_CONNECT_IF_EQ(1,CORE_CONNECT_ARGCOUNT(__VA_ARGS__)) \
([dst valueForKeyPath:__VA_ARGS__]) \
([dst setValue:CORE_CONNECT_HEAD(__VA_ARGS__) forKeyPath:CORE_CONNECT_TAIL(__VA_ARGS__)])
/// LET_KVC_PATH(obj, key1.key2)
/// LET_KVC_PATH(obj, value, key1.key2)
#define LET_KVC_PATH(dst,...) \
CORE_CONNECT_IF_EQ(1,CORE_CONNECT_ARGCOUNT(__VA_ARGS__)) \
([dst valueForKeyPath:@__CODEPP_KEYPATH2(dst, __VA_ARGS__)]) \
([dst setValue:CORE_CONNECT_HEAD(__VA_ARGS__) forKeyPath:@__CODEPP_KEYPATH2(dst, CORE_CONNECT_TAIL(__VA_ARGS__))])

/// 🌟
/// Post notification
/// LET_POST(name)
/// LET_POST(name, object)
/// LET_POST(name, object, userInfo)
#define LET_POST(...) \
CORE_CONNECT_IF_EQ(1,CORE_CONNECT_ARGCOUNT(__VA_ARGS__)) \
    \
([NSNotificationCenter.defaultCenter postNotificationName:__CODEPP_ARG_0(__VA_ARGS__) object:nil]) \
(CORE_CONNECT_IF_EQ(2,CORE_CONNECT_ARGCOUNT(__VA_ARGS__)) \
    \
([NSNotificationCenter.defaultCenter postNotificationName:__CODEPP_ARG_0(__VA_ARGS__) object:__CODEPP_ARG_1(__VA_ARGS__)])\
([NSNotificationCenter.defaultCenter postNotificationName:__CODEPP_ARG_0(__VA_ARGS__) object:__CODEPP_ARG_1(__VA_ARGS__) userInfo:__CODEPP_ARG_THAN_2(__VA_ARGS__)]))
/// LET_NB_ADD(@(9), 9) => @(18)
#define LET_NB_ADD(NB,value) [[NSDecimalNumber decimalNumberWithString:[NB description]] decimalNumberByAdding:[NSDecimalNumber decimalNumberWithString:LET_STRING(value)]]
/// LET_NB_MUT(@(9), 9) => @(81)
#define LET_NB_MUT(NB,value) [[NSDecimalNumber decimalNumberWithString:[NB description]] decimalNumberByAdding:[NSDecimalNumber decimalNumberWithString:LET_STRING(value)]]
/// LET_AFTER_IN(1, {
///   something;
///} )
#define LET_AFTER_IN(time,...) \
dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(time * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{ __VA_ARGS__ });
/// LET_STRING(abc) => @"abc"
#define LET_STRING(S)         @""#S""
#pragma mark - THE Define
/// 🌟
/// weak self
/// THE_WELF => welf
#define THE_WELF  __weak typeof(self) welf = self

/**
 *  🌟
 *  THE_COLOR(HEX)
 *  THE_COLOR(HEX, alpha)
 *  THE_COLOR(r, g, b)
 *  THE_COLOR(r, g, b, alpha)
 */
#define THE_COLOR(...) \
CORE_CONNECT_IF_EQ(1,CORE_CONNECT_ARGCOUNT(__VA_ARGS__))(__CODEPP_HEX_COLOR(__VA_ARGS__,1.0f))(\
CORE_CONNECT_IF_EQ(2,CORE_CONNECT_ARGCOUNT(__VA_ARGS__))(__CODEPP_HEX_COLOR(__VA_ARGS__))(\
CORE_CONNECT_IF_EQ(3,CORE_CONNECT_ARGCOUNT(__VA_ARGS__))(__CODEPP_COLOR(__VA_ARGS__,1.0f))(\
CORE_CONNECT_IF_EQ(4,CORE_CONNECT_ARGCOUNT(__VA_ARGS__))(__CODEPP_COLOR(__VA_ARGS__))(nil))))
/// 🌟
/// THE_WEAKED(var) -> var_weak
#define THE_WEAKED(...) __weak typeof((__VA_ARGS__)) __VA_ARGS__##_weaked = __VA_ARGS__
/// NSObject, x [, something]
/// THE_OBJ(NSObject, x)
/// THE_OBJ(NSObject, x, [NSObject new])
#define THE_OBJ(T,...) \
    CORE_CONNECT_IF_EQ(1,CORE_CONNECT_ARGCOUNT(__VA_ARGS__)) \
    (T *__VA_ARGS__) \
    (T *CORE_CONNECT_HEAD(__VA_ARGS__) = CORE_CONNECT_TAIL(__VA_ARGS__))
/// 🌟
/// THE_VALUE_IN({ value = id...});
///
/// [array addObject:THE_VALUE_IN( {
///     value = [AnyObject new];
/// })];
///
/// THE_VALUE_IN(NSObject *, { value = NSObject *... });
///
/// [array addObject:THE_VALUE_IN(NSObject *, {
///     value = [NSObject new];
/// })];
#define THE_VALUE_IN(...) \
CORE_CONNECT_IF_EQ(1,CORE_CONNECT_ARGCOUNT(__VA_ARGS__)) \
(({id value; __VA_ARGS__ value;})) \
(({CORE_CONNECT_HEAD(__VA_ARGS__) value; CORE_CONNECT_TAIL(__VA_ARGS__) value;}))
/// 🌟
/// THE_NULL_SAFETY(nil) => NSNull
/// THE_NULL_SAFETY(nil, defaultValue) => defaultValue
#define THE_NULL_SAFETY(...) \
CORE_CONNECT_IF_EQ(1,CORE_CONNECT_ARGCOUNT(__VA_ARGS__)) \
(__VA_ARGS__ ?: [NSNull null]) \
(CORE_CONNECT_HEAD(__VA_ARGS__) ?: (CORE_CONNECT_TAIL(__VA_ARGS__)))
/// 🌟
/// THE_NSNULL_SAFATY(NSNULL) => nil
#define THE_NSNULL_SAFETY(...)   (([(__VA_ARGS__) isEqual:[NSNull null]]) ? nil : __VA_ARGS__)
/// 🌟
/// THE_CLASS(NSObject)
#define THE_CLASS(...)       ([__VA_ARGS__ class])
/// THE_NEW(NSObject)
#define THE_NEW(...)       ([__VA_ARGS__ new])
#define THE_ALLOC(...)       ([__VA_ARGS__ alloc])
#define THE_NSNULL  ([NSNull null])
/// 🌟
/// THE_STRING(@"%@", ...);
/// THE_STRING(obj); => [obj description];
#define THE_STRING(...)      \
CORE_CONNECT_IF_EQ(1,CORE_CONNECT_ARGCOUNT(__VA_ARGS__))\
([__VA_ARGS__ description]) \
(([NSString stringWithFormat:__VA_ARGS__]))
/// THE_NB_STRING(123) => @"123"
#define THE_NB_STRING(...)   ([@(__VA_ARGS__) stringValue])
/// THE_STRING_NB(@"123") => @(123)
#define THE_STRING_NB(...)   ([NSDecimalNumber decimalNumberWithString:__VA_ARGS__])
/// 🌟
/// THE_RANDOM(0, 100);  => [0 , 100)
#define THE_RANDOM(from, to) (from + (arc4random()%(to - from)))
/// THE_MUTABLE(immutable) => mutable
#define THE_MUTABLE(...)     ([(__VA_ARGS__) mutableCopy])
/// 🌟
/// THE_PREDICATE(@"@K = %@", id, 1);
#define THE_PREDICATE(...)   ([NSPredicate predicateWithFormat:__VA_ARGS__])
/// 🌟
/// THE_NIB_OBJ(nibName)
#define THE_NIB_OBJ(...)     [NSBundle.mainBundle loadNibNamed:LET_STRING(__VA_ARGS__) owner:nil options:nil].firstObject
/// THE_NIB_VC(ControllerName, var)
#define THE_NIB_VC(T, var)   T* var = [[T alloc] initWithNibName:NSStringFromClass([T class]) bundle:nil]
/// ? :
/// THE_TRINO(condition, if, else);
#define THE_TRINO(condition,A,B)     ((condition)?(A):(B))

/// 结对地组合.
/// THE_DUP_PAIR(SRC, > 0 &&, < 100)
/// =>
/// (SRC > 0 && SRC < 100)
#define THE_DUP_PAIR(SRC, ...) (CORE_CONNECT_FOREACH_CXT(__CODEPP_FOREACH_ORD,,SRC,__VA_ARGS__))
/// 🌟
/// THE_TRINOTHE_IMAGE(@"picktur name");
/// THE_IMAGE(x, @"picktur name");
#define THE_IMAGE(...) \
CORE_CONNECT_IF_EQ(1, CORE_CONNECT_ARGCOUNT(__VA_ARGS__))\
([OPPImage imageNamed:(__VA_ARGS__)])\
(OPPImage *CORE_CONNECT_HEAD(__VA_ARGS__) = [OPPImage imageNamed:(CORE_CONNECT_TAIL(__VA_ARGS__))])
/**
 * Effective when renamed
 NSString *UTF8StringPath = @THE_KEYPATH(str.lowercaseString.UTF8String);
 // => @"lowercaseString.UTF8String"

 NSString *versionPath = @THE_KEYPATH(NSObject, version);
 // => @"version"

 NSString *lowercaseStringPath = @THE_KEYPATH(NSString.new, lowercaseString);
 // => @"lowercaseString"
 */
#define THE_KEYPATH(...) \
@CORE_CONNECT_IF_EQ(1, CORE_CONNECT_ARGCOUNT(__VA_ARGS__))(__CODEPP_KEYPATH1(__VA_ARGS__))(__CODEPP_KEYPATH2(__VA_ARGS__))
/// THE_ANY(x)
#define THE_ANY(var) ((id)(var))
#define THE_NOTHING

#pragma mark - CALL something
/// 🌟
/// CALL_SELF(addObject:x) => [self addObject:x]
#define CALL_SELF(...)           ([self __VA_ARGS__])
/// 🌟
/// THE_WELF;
/// CALL_WELF(addObject:x) => [welf addObject:x]
#define CALL_WELF(...)           ([welf __VA_ARGS__])
/// 🌟
/// Null safety
/// CALL_BLOCK(block);
/// CALL_BLOCK(block, args, ...);
#define CALL_BLOCK(block, ...)   (block ? block(__VA_ARGS__) : ((void *)0))
#define CALL_BLOCK_MAINQUEUE(block, ...) dispatch_async(dispatch_get_main_queue(),^{CALL_BLOCK(block, __VA_ARGS__);})
#define CALL_METHOD(obj, expression) ([obj expression])
/// 🌟
/// CALL_SAFETY(NSNULL,  description) => do nothing
#define CALL_SAFETY(obj, expression) (IS_NOT_NSNULL(obj) ? CALL_METHOD(obj, expression) : ((void *)0))
/// CALL_METHOD_CHAINED(obj, method0, method1, ...) => [...[obj method0] method1] ...]
/// result = CALL_METHOD_CHAINED(obj, method0, method1, ...) => result =  [...[obj method0] method1] ...]
#define CALL_METHOD_CHAINED(obj, ...)  ({ CORE_CONNECT_CONCAT(__CODEPP_CAL,CORE_CONNECT_ARGCOUNT(__VA_ARGS__))(obj, __VA_ARGS__) })

/// 函数调用形式；参数列表: TAG, SEL, ARGS...
//#define CAL_MSG(...) \
//((id(*)(id, SEL, ...))objc_msgSend)(__CODEPP_MSGSEND_TLI(__VA_ARGS__))
///// 指定返回类型的，如值类型；
//#define CAL_MSG_T(rT,...) \
//((T(*)(id, SEL, ...))objc_msgSend)(__CODEPP_MSGSEND_TLI(__VA_ARGS__))
///// 函数调用形式；参数列表: TAG, SEL, ARGS...
//#define CAL_IMP(imp, ...) \
//((id(*)(id, SEL, ...))imp)(__CODEPP_MSGSEND_TLI(__VA_ARGS__))
///// 指定返回类型的，如值类型；
//#define CAL_IMP_T(rT, imp, ...) \
//((T(*)(id, SEL, ...))imp)(__CODEPP_MSGSEND_TLI(__VA_ARGS__))

#pragma mark - DO
/// DO_ONLY(dst = src, condition)
#define DO_ONLY(expression, condition) (condition ? (expression) : (void *)0)

#pragma mark - FILL, pass value
/// 🌟
/// FILL_WHILE(dst = src, condition)
#define FILL_WHILE(expression, condition) DO_ONLY(expression, condition)
/// 🌟
/// FILL_NULL_SAFETY(dst, ⁼, src) => if(src) dst = src;
/// resutl = FILL_NULL_SAFETY(dst, ⁼, src)
#define FILL_NULL_SAFETY(dst, ⁼, src)   (((src) != nil) ? (dst = (src)) : (void *)0 )
/// FILL_NIL(obj0, obj1, int3, ...) => obj0 = nil; obj1 = nil; int3 = 0; ...
#define FILL_NIL(...) CORE_CONNECT_FOREACH_CXT(__CODEPP_FOREACH_FILL_NIL,;,,__VA_ARGS__)

#pragma mark - RETURN value
/// [obj ,]condition
/// RET_IF(condition) => return;
/// RET_IF(obj, condition) === RET_OBJ_IF(obj, condition) => return obj;
#define RET_IF(...) \
CORE_CONNECT_IF_EQ(1,CORE_CONNECT_ARGCOUNT(__VA_ARGS__)) \
    (if((CORE_CONNECT_HEAD(__VA_ARGS__))) {return;})        \
    (if((CORE_CONNECT_TAIL(__VA_ARGS__))) {return CORE_CONNECT_HEAD(__VA_ARGS__);})
/// obj [,condition]
/// RET_OBJ_IF(obj)
/// RET_OBJ_IF(obj, condition) === RET_IF(obj, condition)
#define RET_OBJ_IF(...) \
CORE_CONNECT_IF_EQ(1,CORE_CONNECT_ARGCOUNT(__VA_ARGS__)) \
    (if((__VA_ARGS__)) {return __VA_ARGS__;})        \
    (if((CORE_CONNECT_TAIL(__VA_ARGS__))) {return CORE_CONNECT_HEAD(__VA_ARGS__);})

#pragma mark - IF condition
/// 🌟
/// IF_HAS(condition)
/// IF_HAS(condition, something)
#define IF_HAS(...) \
CORE_CONNECT_IF_EQ(1,CORE_CONNECT_ARGCOUNT(__VA_ARGS__))\
    (if((__VA_ARGS__)))\
    (if((CORE_CONNECT_HEAD(__VA_ARGS__))) CORE_CONNECT_TAIL(__VA_ARGS__))
/// 🌟
/// IF_HAS_NONULLOBJ_IN(expressionForValue, {
///     ...value...
/// });
/// =>
/// if(expression != nil) {
///     ExpressionType value = expression;
///     ...value...
/// }
#define IF_HAS_NONULLOBJ_IN(expression, ...) if((expression)) { typeof((expression)) nonullObj = expression; __VA_ARGS__ }
/// 🌟
/// IF_NOT(condition)
/// IF_NOT(condition, something)
#define IF_NOT(...) \
CORE_CONNECT_IF_EQ(1,CORE_CONNECT_ARGCOUNT(__VA_ARGS__))\
    (if(!(__VA_ARGS__)))\
    (if(!(CORE_CONNECT_HEAD(__VA_ARGS__))) CORE_CONNECT_TAIL(__VA_ARGS__))
/// IF_AS_IN(obj, NSObject, {
///   obj...
/// })
#define IF_AS_IN(obj,T,...) if([obj isKindOfClass:[T class]]) { T *obj##_in = ((id)obj);T *obj = obj##_in; __VA_ARGS__ }
/// 🌟
/// A,B[,EXP]
#define IF_EQ(...) \
CORE_CONNECT_IF_EQ(2,CORE_CONNECT_ARGCOUNT(__VA_ARGS__))\
    (if([((id)__CODEPP_ARG_0(__VA_ARGS__)) isEqual:((id)__CODEPP_ARG_1(__VA_ARGS__))])) \
    (if([((id)__CODEPP_ARG_0(__VA_ARGS__)) isEqual:((id)__CODEPP_ARG_1(__VA_ARGS__))]) {__CODEPP_ARG_THAN_2(__VA_ARGS__)})
#define IF_NOT_EQ(...) \
CORE_CONNECT_IF_EQ(2,CORE_CONNECT_ARGCOUNT(__VA_ARGS__))\
    (if(![((id)__CODEPP_ARG_0(__VA_ARGS__)) isEqual:((id)__CODEPP_ARG_1(__VA_ARGS__))])) \
    (if(![((id)__CODEPP_ARG_0(__VA_ARGS__)) isEqual:((id)__CODEPP_ARG_1(__VA_ARGS__))]) {__CODEPP_ARG_THAN_2(__VA_ARGS__)})
/// A,B[,EXP]
#define IF_EQ_STR(...) \
CORE_CONNECT_IF_EQ(2,CORE_CONNECT_ARGCOUNT(__VA_ARGS__))\
    (if([((id)__CODEPP_ARG_0(__VA_ARGS__)) isEqualToString:((id)__CODEPP_ARG_1(__VA_ARGS__))])) \
    (if([((id)__CODEPP_ARG_0(__VA_ARGS__)) isEqualToString:((id)__CODEPP_ARG_1(__VA_ARGS__))]){__CODEPP_ARG_THAN_2(__VA_ARGS__)})
#define IF_NOT_EQ_STR(...) \
CORE_CONNECT_IF_EQ(2,CORE_CONNECT_ARGCOUNT(__VA_ARGS__))\
    (if(![((id)__CODEPP_ARG_0(__VA_ARGS__)) isEqualToString:((id)__CODEPP_ARG_1(__VA_ARGS__))])) \
    (if(![((id)__CODEPP_ARG_0(__VA_ARGS__)) isEqualToString:((id)__CODEPP_ARG_1(__VA_ARGS__))]){__CODEPP_ARG_THAN_2(__VA_ARGS__)})
/// A,B[,EXP]
#define IF_EQ_NB(...) \
CORE_CONNECT_IF_EQ(2,CORE_CONNECT_ARGCOUNT(__VA_ARGS__))\
    (if([((id)__CODEPP_ARG_0(__VA_ARGS__)) isEqualToNumber:((id)__CODEPP_ARG_1(__VA_ARGS__))])) \
    (if([((id)__CODEPP_ARG_0(__VA_ARGS__)) isEqualToNumber:((id)__CODEPP_ARG_1(__VA_ARGS__))]){__CODEPP_ARG_THAN_2(__VA_ARGS__)})
#define IF_NOT_EQ_NB(...) \
CORE_CONNECT_IF_EQ(2,CORE_CONNECT_ARGCOUNT(__VA_ARGS__))\
    (if(![((id)__CODEPP_ARG_0(__VA_ARGS__)) isEqualToNumber:((id)__CODEPP_ARG_1(__VA_ARGS__))])) \
    (if(![((id)__CODEPP_ARG_0(__VA_ARGS__)) isEqualToNumber:((id)__CODEPP_ARG_1(__VA_ARGS__))]){__CODEPP_ARG_THAN_2(__VA_ARGS__)})
/// IF_AS(obj, NSObject) { something }
/// IF_AS(obj, NSObject, something);
#define IF_AS(...)  \
CORE_CONNECT_IF_EQ(2,CORE_CONNECT_ARGCOUNT(__VA_ARGS__))\
    (if([((id)__CODEPP_ARG_0(__VA_ARGS__)) isKindOfClass:THE_CLASS(__CODEPP_ARG_1(__VA_ARGS__))])) \
    (if([((id)__CODEPP_ARG_0(__VA_ARGS__)) isKindOfClass:THE_CLASS(__CODEPP_ARG_1(__VA_ARGS__))]){__CODEPP_ARG_THAN_2(__VA_ARGS__)})
#pragma mark - LOG 糖
/// Log
#if DEBUG
#define DELOG(...)      NSLog(@"DELOG🐛: %@",[NSString stringWithFormat:__VA_ARGS__])
#define DELOG_OBJ(...)  NSLog(@"DELOG🐛: print object << %@", __VA_ARGS__)
#define DELOG_METHOD    NSLog(@"DELOG🐛: %s", __FUNCTION__);
#define DELOG_DEDEALLOC \
-(void)dealloc {NSLog(@"DELOG🐛, dealoc called: %@ , %p", NSStringFromClass(self.class), self);}

#else
#define DELOG(...)      THE_NOTHING
#define DELOG_OBJ(...)  THE_NOTHING
#define DELOG_METHOD    THE_NOTHING
#define DELOG_DEDEALLOC THE_NOTHING
#endif

#pragma mark - FOR IN
/// 🌟
/// FOR_IN_ITEM(dst) { item }
/// FOR_IN_ITEM(dst, NSObject) { item }
#define FOR_IN_ITEM(...) \
CORE_CONNECT_IF_EQ(1,CORE_CONNECT_ARGCOUNT(__VA_ARGS__))\
(for(typeof([__VA_ARGS__ firstObject]) item in __VA_ARGS__)) \
(for(CORE_CONNECT_TAIL(__VA_ARGS__) item in CORE_CONNECT_HEAD(__VA_ARGS__)))
/**
 * FOR_INT_I(to) { something }
 * FOR_INT_I(from, to)  { something }
 * FOR_INT_I(from, to, var) { something }
 */
#define FOR_INT_I(...) \
CORE_CONNECT_IF_EQ(1,CORE_CONNECT_ARGCOUNT(__VA_ARGS__)) \
(for(NSInteger i = 0; i < __VA_ARGS__; i++)) \
(CORE_CONNECT_IF_EQ(2,CORE_CONNECT_ARGCOUNT(__VA_ARGS__)) \
(for(NSInteger i = CORE_CONNECT_HEAD(__VA_ARGS__); i < CORE_CONNECT_TAIL(__VA_ARGS__); i++)) \
(for(NSInteger __CODEPP_ARG_THAN_2(__VA_ARGS__) = __CODEPP_ARG_0(__VA_ARGS__); __CODEPP_ARG_THAN_2(__VA_ARGS__) < __CODEPP_ARG_1(__VA_ARGS__); __CODEPP_ARG_THAN_2(__VA_ARGS__) ++))) \

#pragma mark - TYPE kind
/// TYPE_AS(NSObject ,x)
#define TYPE_AS(T,var)          ((T)(var))
/// TYPE_AS_IN(obj, NSObject, {
///   obj...
///})
#define TYPED_IN(T,obj,...)   { T *obj##_in = ((id)obj);T *obj = obj##_in; __VA_ARGS__ }
/// TYPE_VAR(NSObject, x);
/// x_NSObject
#define TYPED_OBJ(T, obj)    T * obj##_##T = (id)obj

#pragma mark - IS bool
/// 🌟
#define IS_NOT(...)         IS_FALSES(__VA_ARGS__)
/// IS_TRUES(a, b, c,...) => (a && b && c &&, ...)
#define IS_TRUES(...)       (CORE_CONNECT_FOREACH_CXT(__CODEPP_FOREACH_CAL,&&,,__VA_ARGS__))
/// IS_FALSES(a, b, c,...) => (!a && !b && !c &&, ...)
#define IS_FALSES(...)      (CORE_CONNECT_FOREACH_CXT(__CODEPP_FOREACH_CAL,&&,!,__VA_ARGS__))
/// IS_SOMETRUE(a, b, c,...) => (a || b || c ||, ...)
#define IS_SOMETRUE(...)    (CORE_CONNECT_FOREACH_CXT(__CODEPP_FOREACH_CAL,||,,__VA_ARGS__))
/// IS_SOMEFALSE(a, b, c,...) => (!a || !b || !c ||, ...)
#define IS_SOMEFALSE(...)   (CORE_CONNECT_FOREACH_CXT(__CODEPP_FOREACH_CAL,||,!,__VA_ARGS__))
#define IS_ANYNULL(...)     (!(__VA_ARGS__) && IS_NSNULL(__VA_ARGS__))
#define IS_NOT_ANYNULL(...) ((__VA_ARGS__) && IS_NOT_NSNULL(__VA_ARGS__))
#define IS_NSNULL(...)      ([(__VA_ARGS__) isEqual:NSNull.null])
#define IS_NOT_NSNULL(...)  (![(__VA_ARGS__) isEqual:NSNull.null])
/// IS_KIND(obj, NSObject)
/// IS_KIND(NSObject, obj1, obj2, ...)
#define IS_KIND_OF(obj,T)     ([obj isKindOfClass:[T class]])
/// IS_STRING(obj,)
/// IS_STRING(obj1, obj2, ...)
#define IS_STRING(...)   ([__VA_ARGS__ isKindOfClass:[NSString class]])

#pragma mark - Others
#define LET_CODE_COPY(N, ...)   __CODEPP_COPY##N(__VA_ARGS__)

///
///
///
///
///
///
///
///

#pragma mark - The secondary definition

#define __CODEPP_COLOR(R,G,B,A)  \
[UIColor colorWithRed:TYPE_AS(CGFloat,R)/255.0f \
    green:TYPE_AS(CGFloat,G)/255.0f \
    blue:TYPE_AS(CGFloat,B)/255.0f \
    alpha:TYPE_AS(CGFloat,A)]

#define __CODEPP_HEX_COLOR(HEX,A) \
[UIColor colorWithRed:TYPE_AS(CGFloat,(HEX & 0XFF0000) >> 16)/255.0f \
    green:TYPE_AS(CGFloat,(HEX & 0XFF00) >> 8)/255.0f \
    blue:TYPE_AS(CGFloat,(HEX & 0XFF))/255.0f \
    alpha:TYPE_AS(CGFloat,A)]

#define __CODEPP_KEYPATH1(PATH) \
    (((void)(NO && ((void)PATH, NO)), strchr(# PATH, '.') + 1))

#define __CODEPP_KEYPATH2(OBJ, PATH) \
    (((void)(NO && ((void)OBJ.PATH, NO)), # PATH))


#define __CODEPP_FOREACH_CAL(INDEX, CONTEXT, VAR) CONTEXT(VAR)

#define __CODEPP_FOREACH_ORD(INDEX, CONTEXT, VAR) CONTEXT VAR

#define __CODEPP_FOREACH_FILL_NIL(INDEX, CONTEXT, VAR) VAR = 0

#define __CODEPP_FOREACH_NEW_OBJ(INDEX, CONTEXT, VAR) CONTEXT *VAR = [CONTEXT new]

#define __CODEPP_COPY0(...)
#define __CODEPP_COPY1(...)  __VA_ARGS__
#define __CODEPP_COPY2(...)  __VA_ARGS__ __CODEPP_COPY1(__VA_ARGS__)
#define __CODEPP_COPY3(...)  __VA_ARGS__ __CODEPP_COPY2(__VA_ARGS__)
#define __CODEPP_COPY4(...)  __VA_ARGS__ __CODEPP_COPY3(__VA_ARGS__)
#define __CODEPP_COPY5(...)  __VA_ARGS__ __CODEPP_COPY4(__VA_ARGS__)
#define __CODEPP_COPY6(...)  __VA_ARGS__ __CODEPP_COPY5(__VA_ARGS__)
#define __CODEPP_COPY7(...)  __VA_ARGS__ __CODEPP_COPY6(__VA_ARGS__)
#define __CODEPP_COPY8(...)  __VA_ARGS__ __CODEPP_COPY7(__VA_ARGS__)
#define __CODEPP_COPY9(...)  __VA_ARGS__ __CODEPP_COPY8(__VA_ARGS__)
#define __CODEPP_COPY10(...) __VA_ARGS__ __CODEPP_COPY9(__VA_ARGS__)
#define __CODEPP_COPY11(...) __VA_ARGS__ __CODEPP_COPY10(__VA_ARGS__)
#define __CODEPP_COPY12(...) __VA_ARGS__ __CODEPP_COPY11(__VA_ARGS__)
#define __CODEPP_COPY13(...) __VA_ARGS__ __CODEPP_COPY12(__VA_ARGS__)
#define __CODEPP_COPY14(...) __VA_ARGS__ __CODEPP_COPY13(__VA_ARGS__)
#define __CODEPP_COPY15(...) __VA_ARGS__ __CODEPP_COPY14(__VA_ARGS__)
#define __CODEPP_COPY16(...) __VA_ARGS__ __CODEPP_COPY15(__VA_ARGS__)
#define __CODEPP_COPY17(...) __VA_ARGS__ __CODEPP_COPY16(__VA_ARGS__)
#define __CODEPP_COPY18(...) __VA_ARGS__ __CODEPP_COPY17(__VA_ARGS__)
#define __CODEPP_COPY19(...) __VA_ARGS__ __CODEPP_COPY18(__VA_ARGS__)
#define __CODEPP_COPY20(...) __VA_ARGS__ __CODEPP_COPY19(__VA_ARGS__)

#define __CODEPP_MSGSEND_TLI(...) \
CORE_CONNECT_IF_EQ(2,CORE_CONNECT_ARGCOUNT(__VA_ARGS__))\
    (__CODEPP_ARG_0(__VA_ARGS__),__CODEPP_ARG_1(__VA_ARGS__))\
    (__CODEPP_ARG_0(__VA_ARGS__),__CODEPP_ARG_1(__VA_ARGS__),__CODEPP_ARG_THAN_2(__VA_ARGS__))

#define __CODEPP_ARG_0(_0, ...) _0
#define __CODEPP_ARG_1(_0, _1, ...) _1
#define __CODEPP_ARG_THAN_2(_0, _1, ...) __VA_ARGS__

/// CALL chains
#define __CODEPP_CAL0(obj,...)
#define __CODEPP_CAL1(obj,...)  [obj CORE_CONNECT_HEAD(__VA_ARGS__)];
#define __CODEPP_CAL2(obj,...)  typeof([obj CORE_CONNECT_HEAD(__VA_ARGS__)]) __LINC_VAR1 = [obj CORE_CONNECT_HEAD(__VA_ARGS__)]; __CODEPP_CAL1(__LINC_VAR1,CORE_CONNECT_TAIL(__VA_ARGS__))
#define __CODEPP_CAL3(obj,...)  typeof([obj CORE_CONNECT_HEAD(__VA_ARGS__)]) __LINC_VAR2 = [obj CORE_CONNECT_HEAD(__VA_ARGS__)]; __CODEPP_CAL2(__LINC_VAR2,CORE_CONNECT_TAIL(__VA_ARGS__))
#define __CODEPP_CAL4(obj,...)  typeof([obj CORE_CONNECT_HEAD(__VA_ARGS__)]) __LINC_VAR3 = [obj CORE_CONNECT_HEAD(__VA_ARGS__)]; __CODEPP_CAL3(__LINC_VAR3,CORE_CONNECT_TAIL(__VA_ARGS__))
#define __CODEPP_CAL5(obj,...)  typeof([obj CORE_CONNECT_HEAD(__VA_ARGS__)]) __LINC_VAR4 = [obj CORE_CONNECT_HEAD(__VA_ARGS__)]; __CODEPP_CAL4(__LINC_VAR4,CORE_CONNECT_TAIL(__VA_ARGS__))
#define __CODEPP_CAL6(obj,...)  typeof([obj CORE_CONNECT_HEAD(__VA_ARGS__)]) __LINC_VAR5 = [obj CORE_CONNECT_HEAD(__VA_ARGS__)]; __CODEPP_CAL5(__LINC_VAR5,CORE_CONNECT_TAIL(__VA_ARGS__))
#define __CODEPP_CAL7(obj,...)  typeof([obj CORE_CONNECT_HEAD(__VA_ARGS__)]) __LINC_VAR6 = [obj CORE_CONNECT_HEAD(__VA_ARGS__)]; __CODEPP_CAL6(__LINC_VAR6,CORE_CONNECT_TAIL(__VA_ARGS__))
#define __CODEPP_CAL8(obj,...)  typeof([obj CORE_CONNECT_HEAD(__VA_ARGS__)]) __LINC_VAR7 = [obj CORE_CONNECT_HEAD(__VA_ARGS__)]; __CODEPP_CAL7(__LINC_VAR7,CORE_CONNECT_TAIL(__VA_ARGS__))
#define __CODEPP_CAL9(obj,...)  typeof([obj CORE_CONNECT_HEAD(__VA_ARGS__)]) __LINC_VAR8 = [obj CORE_CONNECT_HEAD(__VA_ARGS__)]; __CODEPP_CAL8(__LINC_VAR8,CORE_CONNECT_TAIL(__VA_ARGS__))
#define __CODEPP_CAL10(obj,...) typeof([obj CORE_CONNECT_HEAD(__VA_ARGS__)]) __LINC_VAR9 = [obj CORE_CONNECT_HEAD(__VA_ARGS__)]; __CODEPP_CAL9(__LINC_VAR9,CORE_CONNECT_TAIL(__VA_ARGS__))
#define __CODEPP_CAL11(obj,...) typeof([obj CORE_CONNECT_HEAD(__VA_ARGS__)]) __LINC_VAR10 = [obj CORE_CONNECT_HEAD(__VA_ARGS__)]; __CODEPP_CAL10(__LINC_VAR10,CORE_CONNECT_TAIL(__VA_ARGS__))
#define __CODEPP_CAL12(obj,...) typeof([obj CORE_CONNECT_HEAD(__VA_ARGS__)]) __LINC_VAR11 = [obj CORE_CONNECT_HEAD(__VA_ARGS__)]; __CODEPP_CAL11(__LINC_VAR12,CORE_CONNECT_TAIL(__VA_ARGS__))
#define __CODEPP_CAL13(obj,...) typeof([obj CORE_CONNECT_HEAD(__VA_ARGS__)]) __LINC_VAR12 = [obj CORE_CONNECT_HEAD(__VA_ARGS__)]; __CODEPP_CAL12(__LINC_VAR13,CORE_CONNECT_TAIL(__VA_ARGS__))
#define __CODEPP_CAL14(obj,...) typeof([obj CORE_CONNECT_HEAD(__VA_ARGS__)]) __LINC_VAR13 = [obj CORE_CONNECT_HEAD(__VA_ARGS__)]; __CODEPP_CAL13(__LINC_VAR14,CORE_CONNECT_TAIL(__VA_ARGS__))
#define __CODEPP_CAL15(obj,...) typeof([obj CORE_CONNECT_HEAD(__VA_ARGS__)]) __LINC_VAR14 = [obj CORE_CONNECT_HEAD(__VA_ARGS__)]; __CODEPP_CAL14(__LINC_VAR15,CORE_CONNECT_TAIL(__VA_ARGS__))
#define __CODEPP_CAL16(obj,...) typeof([obj CORE_CONNECT_HEAD(__VA_ARGS__)]) __LINC_VAR15 = [obj CORE_CONNECT_HEAD(__VA_ARGS__)]; __CODEPP_CAL15(__LINC_VAR16,CORE_CONNECT_TAIL(__VA_ARGS__))
#define __CODEPP_CAL17(obj,...) typeof([obj CORE_CONNECT_HEAD(__VA_ARGS__)]) __LINC_VAR16 = [obj CORE_CONNECT_HEAD(__VA_ARGS__)]; __CODEPP_CAL16(__LINC_VAR17,CORE_CONNECT_TAIL(__VA_ARGS__))
#define __CODEPP_CAL18(obj,...) typeof([obj CORE_CONNECT_HEAD(__VA_ARGS__)]) __LINC_VAR17 = [obj CORE_CONNECT_HEAD(__VA_ARGS__)]; __CODEPP_CAL17(__LINC_VAR18,CORE_CONNECT_TAIL(__VA_ARGS__))
#define __CODEPP_CAL19(obj,...) typeof([obj CORE_CONNECT_HEAD(__VA_ARGS__)]) __LINC_VAR18 = [obj CORE_CONNECT_HEAD(__VA_ARGS__)]; __CODEPP_CAL18(__LINC_VAR19,CORE_CONNECT_TAIL(__VA_ARGS__))
#define __CODEPP_CAL20(obj,...) typeof([obj CORE_CONNECT_HEAD(__VA_ARGS__)]) __LINC_VAR20 = [obj CORE_CONNECT_HEAD(__VA_ARGS__)]; __CODEPP_CAL19(__LINC_VAR20,CORE_CONNECT_TAIL(__VA_ARGS__));
 
#endif /* CodePP_h */
