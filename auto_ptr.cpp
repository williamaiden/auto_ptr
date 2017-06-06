#include <memory>
#include <utility> //std::move()
class demo {
public:
	demo() : uptr(std::make_unique<int[]>(10)){
		printf("demo\n");
		for (int i = 0; i < 10; ++i){
			uptr[i] = i;
		}
	}
	~demo(){
		printf("~demo\n");
	}
	void show(){
		printf("%d\n",uptr[9]);
	}
private:
	std::unique_ptr<int[]> uptr;
};

void my_shared_ptr(){
	///auto sptr = std::make_shared<int[]>(10);
	///sptr[6] = 20;
	auto sptr = std::make_shared<demo>();
	sptr->show();
}

void auto_run_fun(FILE* f){
	printf("auto running.\n");
}

void my_shared_ptr2(){
	FILE* f = nullptr;
	std::shared_ptr<FILE> file_ptr(f, auto_run_fun);
}

void my_shared_ptr3(){
	/*demo* d = new demo();
	std::shared_ptr<demo> sptr1(d);
	std::shared_ptr<demo> sptr2(d);///~demo() error
	*/
	auto sptr3 = std::make_shared<demo>();
	std::shared_ptr<demo> sptr4(sptr3); ///shared_ptr拷贝构造函数
}

std::shared_ptr<demo> my_shared_ptr4(){
	auto sptr = std::make_shared<demo>();
	return sptr;
}

void my_unique_ptr(){
	auto uptr = std::make_unique<int[]>(10);
	uptr[5] = 17;
	printf("%d\n", uptr[5]);
}

void my_unique_ptr2(){
	auto uptr = std::make_unique<demo>();
	uptr->show();
	std::unique_ptr<demo> uptr2(new demo());///等效写法
	uptr2->show();
}

void my_unique_ptr3(){
	auto uptr = std::make_unique<int>(42);
	printf("%d\n",*uptr);//42
	///std::unique_ptr<int> uptr1 = uptr; ///unique_ptr无拷贝构造函数
	///std::unique_ptr<int> uptr1(uptr);  ///等效写法
	std::unique_ptr<int> uptr2 = std::move(uptr);
	///printf("%d\n",*uptr); ///error 所有权已交给uptr2
	printf("%d\n", *uptr2);
}

///weak_ptr -> shared_ptr
void my_weak_ptr(){
	std::weak_ptr<demo> wptr;
	{
		auto sptr = std::make_shared<demo>();
		wptr = sptr;
		auto sptr2 = wptr.lock();
		if (!wptr.expired()){///等价于sptr3 != nullptr
			printf("shared_ptr ok\n");
			sptr2->show();
		}
	}
	if (wptr.expired()){
		printf("shared_ptr deleted\n");
	}
}

int main(void){
	///my_shared_ptr();
	///my_unique_ptr2();
	///my_shared_ptr2();
	///my_shared_ptr3();
	///my_shared_ptr4()->show();
	///my_unique_ptr3();
	my_weak_ptr();
	return 0;
}
