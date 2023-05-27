[1mdiff --git a/CPP04/ex00/sources/main.cpp b/CPP04/ex00/sources/main.cpp[m
[1mindex 5f09d2f..e4381fc 100644[m
[1m--- a/CPP04/ex00/sources/main.cpp[m
[1m+++ b/CPP04/ex00/sources/main.cpp[m
[36m@@ -38,7 +38,18 @@[m [mvoid test_animal_copy(void)[m
 	std::cout << copy->getType() << std::endl;[m
 	copy->makeSound();[m
 [m
[32m+[m	[32mconst Dog *first = new Dog();[m[41m[m
[32m+[m	[32mconst Dog *second = new Dog(*first);[m[41m[m
[32m+[m[41m[m
[32m+[m	[32mstd::cout << first->getType() << std::endl;[m[41m[m
[32m+[m	[32mfirst->makeSound();[m[41m[m
[32m+[m[41m[m
[32m+[m	[32mstd::cout << second->getType() << std::endl;[m[41m[m
[32m+[m	[32msecond->makeSound();[m[41m[m
[32m+[m[41m[m
 	delete dog;[m
[32m+[m	[32mdelete first;[m[41m[m
[32m+[m	[32mdelete second;[m[41m[m
 }[m
 [m
 void test_inheritance(void)[m
[36m@@ -68,7 +79,7 @@[m [mvoid test_animal_instance(void)[m
 	delete meta;[m
 }[m
 [m
[31m-int main()[m
[32m+[m[32mint main(void)[m[41m[m
 {[m
 	test_animal_instance();[m
 	test_inheritance();[m
