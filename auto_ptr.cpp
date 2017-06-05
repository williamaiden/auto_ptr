#include <memory>
class demo {
public:
	demo() : uptr(std::make_unique<int[]>(10)){
		for (int i = 0; i < 10; ++i){
			uptr[i] = i;
		}
	}
	void show(){
		printf("%d ",uptr[9]);
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
	demo*
}

void my_unique_ptr(){
	auto uptr = std::make_unique<int[]>(10);
	uptr[5] = 17;
	printf("%d\n", uptr[5]);
}

void my_unique_ptr2(){
	auto uptr = std::make_unique<demo>();
	uptr->show();
	std::unique_ptr<demo> uptr2(new demo());///写法等效
	uptr2->show();
}

int main(void){
	///my_shared_ptr();
	///my_unique_ptr2();
	my_shared_ptr2();
	return 0;
}
