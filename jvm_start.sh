#!/bin/bash
# ch5 for simple instruction, like math, branch, etc.
#/home/strike/workspace/mini-jvm/build/src/main \
#    --Xjre /usr/lib/jvm/java-8-openjdk-amd64/jre \
#    --classpath /home/strike/workspace/mini-jvm \
#    --mainclass GaussTest

# ch6 for ldc, new ,instanceof, checkcast, etc.
#/home/strike/workspace/mini-jvm/build/src/main \
#    --Xjre /usr/lib/jvm/java-8-openjdk-amd64/jre \
#    --classpath /home/strike/workspace/mini-jvm \
#    --mainclass MyObject

# ch7 for method invoke test
#/home/strike/workspace/mini-jvm/build/src/main \
#    --Xjre /usr/lib/jvm/java-8-openjdk-amd64/jre \
#    --classpath /home/strike/workspace/mini-jvm \
#    --verboseInstFlag true                  \
#    --verboseClassFlag true                  \
#    --mainclass InvokeDemo

#/home/strike/workspace/mini-jvm/build/src/main \
#    --Xjre /usr/lib/jvm/java-8-openjdk-amd64/jre \
#    --classpath /home/strike/workspace/mini-jvm \
#    --verboseInstFlag true                  \
#    --verboseClassFlag true                  \
#    --mainclass FibonacciTest

# ch8 for array operations
#/home/strike/workspace/mini-jvm/build/src/main \
#    --Xjre /usr/lib/jvm/java-8-openjdk-amd64/jre \
#    --classpath /home/strike/workspace/mini-jvm \
#    --verboseInstFlag false                  \
#    --verboseClassFlag false                  \
#    --mainclass BubbleSortTest

# ch8 for string operations
/home/strike/workspace/mini-jvm/build/src/main \
    --Xjre /usr/lib/jvm/java-8-openjdk-amd64/jre \
    --classpath /home/strike/workspace/mini-jvm \
    --verboseInstFlag false                  \
    --verboseClassFlag false                  \
    --mainclass HelloWorld  \
    hello world this is args test

