# StarterProject-iOS

MaxLeap iOS sdk 的模版项目。

## 怎么运行

1. 前往 [MaxLeap 控制台](https://maxleap.cn)，创建 MaxLeap 应用，记录 ApplicationId 和 ClientKey。
2. 克隆这个仓库，打开 Xcode 项目文件 `Demo-Auth-iOS/Auth.xcodeproj`.
3. 在 `AppDelegate.m` 中填写你的 MaxLeap 应用 ID 和 client key.
4. 编译运行.

## 测试 SDK

1. 前往 开发中心 -> 云数据库，点击新建表，创建一个名字为 TestObject 的表。

2. 请确保 `ViewController.h` 文件中引用了我们 SDK 的头文件。

    ```
    #import <MaxLeap/MaxLeap.h>
    ```

3. 把下面的代码复制粘贴到你的项目中，可以放在 `ViewController.m` 的 `-viewDidLoad` 方法中。

    ```
    MLObject *testObject = [MLObject objectWithClassName:@"TestObject"];
    testObject[@"foo"] = @"bar";
    [testObject saveInBackgroundWithBlock:^(BOOL succeeded, NSError * _Nullable error) {
        if (succeeded) {
            // 保存成功
        } else {
            if (error.code == kMLErrorUnauthorized) {
                // 请检查 ApplicationId 和 ClientKey 是否正确
            } else if (error.code == 700) {
                // Class: TestObject not exists.
                // 请执行第一步，前往控制台的云数据库，创建表 TestObject
            } else {
                // ...
            }
        }
    }];
    ```

4. 运行你的应用。`TestObject` 表中应该插入了一条新的数据。然后刷新控制台的 TestObject 表，应该就能够看到这条数据。