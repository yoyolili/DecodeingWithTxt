/*
 *Xcode在UTF16的编码下才能正确显示中文，因此在显示txt文件时需要针对ANSI编码和Unicode编码分别进行解码
 */


NSString *filePath = [[NSBundle mainBundle] pathForResource:@"txt name" ofType:@"txt"];

NSData *data = [NSData dataWithContentsOfFile:filePath];

//UINICODE编码
NSString *isUNICODE = [[NSString alloc] initWithData:data encoding:NSUTF8StringEncoding];

//ANSI编码
NSString *isANSI = [[NSString alloc] initWithData:data encoding:-2147482062];

if (isUNICODE) {
    NSString *retStr = [[NSString alloc] initWithCString:[isUNICODE UTF8String] encoding:NSUTF8StringEncoding];
    NSData *UTF16Data = [retStr dataUsingEncoding:NSUTF16StringEncoding];
    NSString *CNStr = [[NSString alloc] initWithData:UTF16Data encoding:NSUTF16StringEncoding];
                
}else if(isANSI){
    NSData *ANData = [isANSI dataUsingEncoding:NSUTF16StringEncoding];
    NSString *CNStr = [[NSString alloc] initWithData:ANData encoding:NSUTF16StringEncoding];
}
