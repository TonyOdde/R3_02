#include <iostream>
#include <cstring>
#include "list.h"
#include "test.h"
using namespace std;

class TestList : public tests::Test
{
private:
	void test_construct_destruct()
	{
		List l;
		auto it = l.begin();
		assert_true(it.equals(l.end()), "list empty");
	}
	void test_add()
	{
		List l;
		for (int i = 0; i < 2; i++)
			l.addLast(i);
		l.addFirst(-1000);
		l.addFirst(10);
		auto it = l.begin();
		assert_equal(10, it.getValue(), "add first (1)");
		it.next();
		assert_equal(-1000, it.getValue(), "add first (2)");
		it.next();        
		assert_equal(0, it.getValue(), "add last (1)");
		it.next();
		assert_equal(1, it.getValue(), "add last (2)");
	}
	void test_size()
	{
		List l;
		l.addFirst(10);
		l.addLast(15);
		l.addLast(20);
		assert_equal(3, l.size(),"size");
	}
	void test_find()
	{
		List l;
		l.addFirst(10);
		l.addLast(15);
		l.addLast(20);
		IteratorList i = l.find(15);
		assert_equal(15, i.getValue(), "find existing value");
		i = l.find(25);
		assert_true(i.equals(l.end()), "find not existing value");		
	}
	
	void test_get()
	{
		List l;
		l.addFirst(10);
		l.addLast(15);
		l.addLast(20);
		assert_equal(10, l.get(0), "get(0)");
		assert_equal(20, l.get(2), "get(2)");
		assert_throws<ExceptionList>([&]() {l.get(3); }, "get(3) throws exception");
	}
protected:
	void test_code() override
	{
		test_construct_destruct();
		test_add();
		test_size();
		test_find();
		test_get();
	}
};
int main()
{
	TestList test;
	test.run();

	return 0;
}
