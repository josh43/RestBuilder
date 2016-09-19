
//-------GENERATED FILE-------
#import "Get.h"
@implementation Get 
static const NSString * baseURL = @"ttp://localhost:3000";
+(NSURLSessionTask * ) getBasicTaskWithStringURL:(NSString *) stringURL
        completionHandler:(void (^)(NSData * __nullable data, NSURLResponse * __nullable response, NSError * __nullable error))completionHandler{
    NSURL* url = [NSURL URLWithString:[stringURL stringByAddingPercentEncodingWithAllowedCharacters:[NSCharacterSet URLQueryAllowedCharacterSet]]];
    NSMutableURLRequest *urlRequest = [NSMutableURLRequest requestWithURL:url];
    [urlRequest setHTTPMethod:@"GET"];


    NSURLSessionTask *task = [[NSURLSession sharedSession] dataTaskWithRequest:urlRequest completionHandler:completionHandler];

    return task;
}

+(void) getqueryWithProjectionusername:(NSString *)username  andpass:(NSString *)pass andarrString:(NSArray *)arrString withComp:(void (^)(BOOL, id))onCompletion{
	NSString * route = [NSString stringWithFormat:@"ttp://localhost:3000/queryWithProjection/%@/%@/%@",username,pass,arrString];
	NSURLSessionTask  * task = [Get getBasicTaskWithStringURL:route completionHandler:^(NSData *data, NSURLResponse *response, NSError *error) {
		basicResponseHandler(DictionaryResponseHandler);
	}];
	[task resume];


}

+(void) gethelloWorldwithComp:(void (^)(BOOL, id))onCompletion{
	NSString * route = [NSString stringWithFormat:@"ttp://localhost:3000/helloWorld"];
	NSURLSessionTask  * task = [Get getBasicTaskWithStringURL:route completionHandler:^(NSData *data, NSURLResponse *response, NSError *error) {
		basicResponseHandler(DictionaryResponseHandler);
	}];
	[task resume];


}

+(void) gethelloWorldComplexusername:(NSString *)username  andpass:(NSString *)pass withComp:(void (^)(BOOL, id))onCompletion{
	NSString * route = [NSString stringWithFormat:@"ttp://localhost:3000/helloWorldComplex/%@/andPass/%@",username,pass];
	NSURLSessionTask  * task = [Get getBasicTaskWithStringURL:route completionHandler:^(NSData *data, NSURLResponse *response, NSError *error) {
		basicResponseHandler(ArrayResponseHandler);
	}];
	[task resume];


}

@end // Get.m
