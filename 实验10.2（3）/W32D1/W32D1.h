// 下列 ifdef 块是创建使从 DLL 导出更简单的
// 宏的标准方法。此 DLL 中的所有文件都是用命令行上定义的 W32D1_EXPORTS
// 符号编译的。在使用此 DLL 的
// 任何其他项目上不应定义此符号。这样，源文件中包含此文件的任何其他项目都会将
// W32D1_API 函数视为是从 DLL 导入的，而此 DLL 则将用此宏定义的
// 符号视为是被导出的。
#ifdef W32D1_EXPORTS
#define W32D1_API __declspec(dllexport)
#else
#define W32D1_API __declspec(dllimport)
#endif

// 此类是从 W32D1.dll 导出的
class W32D1_API CW32D1 {
public:
	CW32D1(void);
	// TODO:  在此添加您的方法。
};

extern W32D1_API int nW32D1;

W32D1_API int fnW32D1(void); 
W32D1_API int Factorial(int n);
