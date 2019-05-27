//
//  MacroDefinition.h
//  MacroDefinitionDemo
//
//  Created by 新风作浪 on 13-6-9, Maintain by Cyruschang
//  Copyright (c) 2013年 SpinningSphere Labs. All rights reserved.
//

#ifndef MacroDefinition_h
#define MacroDefinition_h

//-------------------获取设备大小-------------------------
// 获取状态栏高度
#define kStatusBarHeight ([[UIApplication sharedApplication] statusBarFrame].size.height)
// 导航栏高度
#define kNavBarHeight 44.0f
// 底部分栏控制器高度
#define kTabBarHeight ([[UIApplication sharedApplication] statusBarFrame].size.height > 20.0f ? 83.0f : 49.0f)
// 顶部高度
#define kTopHeight (kStatusBarHeight + kNavBarHeight)

#define kSafeArea_Top (kStatusBarHeight > 20.f ? 44: 20)
#define kSafeArea_Bottom (kStatusBarHeight > 20.f ? 34: 0)
#define kLine_MinHeight (1.0/ [UIScreen mainScreen].scale)
// 获取屏幕 宽度、高度
#define kScreenWidth ([[UIScreen mainScreen] bounds].size.width)
#define kScreenHeight ([[UIScreen mainScreen] bounds].size.height)
#define kScreenBounds [UIScreen mainScreen].bounds

//-------------------获取设备大小-------------------------

// 不同屏幕尺寸字体适配
#define kScreenWidthRatio  (kScreenWidth / 375.0)
#define kScreenHeightRatio (kScreenHeight / 667.0)

#define IMAGE_NAMED(name) [UIImage imageNamed:name]


//-------------------打印日志-------------------------
// 替换系统打印语句，release时不打印
#ifndef __OPTIMIZE__
#define NSLog(format, ...)\
{\
NSDateFormatter *dateFormatter = [[NSDateFormatter alloc] init];\
[dateFormatter setDateStyle:NSDateFormatterMediumStyle];\
[dateFormatter setTimeStyle:NSDateFormatterShortStyle];\
[dateFormatter setDateFormat:@"HH:mm:ss:SSSSSS"]; \
NSString *str = [dateFormatter stringFromDate:[NSDate date]];\
printf("%s class: <%p %s:(%d) > method: %s \n%s\n",[str UTF8String] ,self, [[[NSString stringWithUTF8String:__FILE__] lastPathComponent] UTF8String], __LINE__, __PRETTY_FUNCTION__, [[NSString stringWithFormat:(format), ##__VA_ARGS__] UTF8String] );\
}
#else
#define NSLog(...) {}
#endif
//-------------------打印日志-------------------------


//----------------------沙盒路径----------------------------
#define PATH_OF_APP_HOME    NSHomeDirectory()
#define PATH_OF_TEMP        NSTemporaryDirectory()
#define PATH_OF_DOCUMENT    [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) objectAtIndex:0]

// 非空判断
// 字符串非空
#define ISNOTEMPTY_STRING(s) (s && [s isKindOfClass:[NSString class]] && ![s isEqualToString:@""] && ![s isEqual:[NSNull null]])

// 数组非空
#define ISNOTEMPTY_ARRAY(arr) (arr && [arr isKindOfClass:[NSArray class]] && arr.count > 0 && ![arr isEqual:[NSNull null]])

// 字典非空
#define ISNOTEMPTY_DICTIONARY(dict) (dict && [dict isKindOfClass:[NSDictionary class]] && dict.count > 0 && ![dict isEqual:[NSNull null]])

// 集合非空
#define ISNOTEMPTY_SET(set) (set && [set isKindOfClass:[NSSet class]] && set.count > 0 && ![set isEqual:[NSNull null]])

// number非空
#define ISNOTEMPTY_NUMBER(number) (number && [number isKindOfClass:[NSNumber class]] && ![number isEqual:[NSNull null]] && ![number isEqualToNumber:[NSDecimalNumber notANumber]])

//----------------------系统----------------------------

// 获取系统版本
#define IOS_VERSION [[[UIDevice currentDevice] systemVersion] floatValue]
#define CurrentSystemVersion [[UIDevice currentDevice] systemVersion]

// 获取当前语言
#define CurrentLanguage ([[NSLocale preferredLanguages] objectAtIndex:0])

// 判断是否 Retina屏、设备是否%fhone 5、是否是iPad
#define isRetina ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(640, 960), [[UIScreen mainScreen] currentMode].size) : NO)
#define iPhone5 ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(640, 1136), [[UIScreen mainScreen] currentMode].size) : NO)
#define isPad (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad)


//判断是真机还是模拟器
#if TARGET_OS_IPHONE
// iPhone Device
#endif

#if TARGET_IPHONE_SIMULATOR
// iPhone Simulator
#endif

// 检查系统版本
#define SYSTEM_VERSION_EQUAL_TO(v)                  ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedSame)
#define SYSTEM_VERSION_GREATER_THAN(v)              ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedDescending)
#define SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(v)  ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] != NSOrderedAscending)
#define SYSTEM_VERSION_LESS_THAN(v)                 ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedAscending)
#define SYSTEM_VERSION_LESS_THAN_OR_EQUAL_TO(v)     ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] != NSOrderedDescending)

/* 发送通知 */
#define POST_MSG_WITH_OBJ_DICT(aName, anObject, aUserInfo)     [[NSNotificationCenter defaultCenter] \
postNotificationName:aName \
object:anObject \
userInfo:aUserInfo]
#define POST_MSG_WITH_OBJ(aName, anObject)      POST_MSG_WITH_OBJ_DICT(aName, anObject, nil)
#define POST_MSG(aName)                         POST_MSG_WITH_OBJ(aName, nil)


//----------------------系统----------------------------


//----------------------内存----------------------------

//使用ARC和不使用ARC
#if __has_feature(objc_arc)
//compiling with ARC
#else
// compiling without ARC
#endif

#pragma mark - common functions
#define RELEASE_SAFELY(__POINTER) { [__POINTER release]; __POINTER = nil; }

//释放一个对象
#define SAFE_DELETE(P) if(P) { [P release], P = nil; }

#define SAFE_RELEASE(x) [x release];x=nil



//----------------------内存----------------------------


//----------------------图片----------------------------

//读取本地图片
#define LOADIMAGE(file,ext) [UIImage imageWithContentsOfFile:[[NSBundle mainBundle]pathForResource:file ofType:ext]]

//定义UIImage对象
#define IMAGE(A) [UIImage imageWithContentsOfFile:[[NSBundle mainBundle] pathForResource:A ofType:nil]]

//建议使用前两种宏定义,性能高于后者
//----------------------图片----------------------------



//----------------------颜色类---------------------------
// rgb颜色转换（16进制->10进制）
#define UIColorFromRGB(rgbValue) [UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 green:((float)((rgbValue & 0xFF00) >> 8))/255.0 blue:((float)(rgbValue & 0xFF))/255.0 alpha:1.0]

//带有RGBA的颜色设置
#define COLOR(R, G, B, A) [UIColor colorWithRed:R/255.0 green:G/255.0 blue:B/255.0 alpha:A]

// 获取RGB颜色
#define RGBA(r,g,b,a) [UIColor colorWithRed:r/255.0f green:g/255.0f blue:b/255.0f alpha:a]
#define RGB(r,g,b) RGBA(r,g,b,1.0f)

//背景色
#define BACKGROUND_COLOR [UIColor colorWithRed:242.0/255.0 green:236.0/255.0 blue:231.0/255.0 alpha:1.0]

//清除背景色
#define CLEARCOLOR [UIColor clearColor]

#pragma mark - color functions
#define RGBCOLOR(r,g,b) [UIColor colorWithRed:(r)/255.0f green:(g)/255.0f blue:(b)/255.0f alpha:1]
#define RGBACOLOR(r,g,b,a) [UIColor colorWithRed:(r)/255.0f green:(g)/255.0f blue:(b)/255.0f alpha:(a)]

//----------------------颜色类--------------------------



//----------------------其他----------------------------

//方正黑体简体字体定义
#define FONT(F) [UIFont fontWithName:@"FZHTJW--GB1-0" size:F]


//定义一个API
#define APIURL                @"http://xxxxx/"
//登陆API
#define APILogin              [APIURL stringByAppendingString:@"Login"]

//设置View的tag属性
#define VIEWWITHTAG(_OBJECT, _TAG)    [_OBJECT viewWithTag : _TAG]
//程序的本地化,引用国际化的文件
#define MyLocal(x, ...) NSLocalizedString(x, nil)

//G－C－D
#define BACK(block) dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), block)
#define MAIN(block) dispatch_async(dispatch_get_main_queue(),block)

//NSUserDefaults 实例化
#define USER_DEFAULT [NSUserDefaults standardUserDefaults]


//由角度获取弧度 有弧度获取角度
#define degreesToRadian(x) (M_PI * (x) / 180.0)
#define radianToDegrees(radian) (radian*180.0)/(M_PI)



//单例化一个类
#define SYNTHESIZE_SINGLETON_FOR_CLASS(classname) \
\
static classname *shared##classname = nil; \
\
+ (classname *)shared##classname \
{ \
@synchronized(self) \
{ \
if (shared##classname == nil) \
{ \
shared##classname = [[self alloc] init]; \
} \
} \
\
return shared##classname; \
} \
\
+ (id)allocWithZone:(NSZone *)zone \
{ \
@synchronized(self) \
{ \
if (shared##classname == nil) \
{ \
shared##classname = [super allocWithZone:zone]; \
return shared##classname; \
} \
} \
\
return nil; \
} \
\
- (id)copyWithZone:(NSZone *)zone \
{ \
return self; \
}



#endif
