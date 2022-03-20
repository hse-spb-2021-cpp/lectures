22-220314\03-template-details\11-args.cpp:
* show that you can omit all template arguments because of CTAD
* show that `template<typename> typename` with default args is from C++17 and Clang disables it by default

22-220314\03-template-details\14-definition.cpp:
* show template<> template<>.

22-220314\04-template-multiple-tu:
* add class template forward declaration
* add rules about different names/defaults in declaration/definition
* add ODR violation reminder

02-function-template\05-ctad:
* CTAD works with constructors but not conversions

02-function-template\06-deduction-fails:
* constructors are not enumerated as well
* ambiguous base (does not matter if private)
