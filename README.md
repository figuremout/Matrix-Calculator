A scratch C implementation for some of linear algebra algorithms.
It is available for C/CPP/Python/Golang.
It is easy to comprehend, modify and use.

The cause of creating this project is just to relieve the boredom of learning linear algebra.

# Requirements
- nvcc
- valgrind
- lcov

# TODO
- [superlu](https://github.com/xiaoyeli/superlu) 是 scipy 使用的库，可以参考它的项目目录
- 遵循 BLAS 接口标准
- benchmark
- 并行计算
- testing / assert。googletest，用 cblas 作为标准答案进行测试？
- 封装(`extern "C"`)成 cpp，用上运算符重载
- map reduce
- 数值稳定 控制误差 迭代法
- numerical recipes in c
- 直接三角分解法求 lu

    matlib/pynnthon/       Python interface
    matlib/golang/       Golang interface
    matlib/src/          C source code
    matlib/testing/      testcases
    matlib/example/      example programs
    matlib/src/mat.c     matrix
    matlib/src/lu.c      LU decomposition
    matlib/src/gepp.c    Gaussian Elimination partial pivoting 
    matlib/src/ev.c      eigenvalue
