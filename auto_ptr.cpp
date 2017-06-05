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

void my_unique_ptr(){
	auto uptr = std::make_unique<int[]>(10);
	uptr[5] = 17;
	printf("%d\n", uptr[5]);
}

int main(void){
	my_shared_ptr();
	return 0;
}
