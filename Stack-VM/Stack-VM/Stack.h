typedef struct node_s {
	int data;
	struct node_s *prev;
} node;

typedef struct top_s {
	struct node_s *top = nullptr;
} top;

class Stack
{
private:
	top* s = new top;
	void push_ins(top* data, int val);
	int pop_ins(top* data);
	bool isEmpty_ins(top* data);
public:
	Stack();
	~Stack();
	void push(int val);
	int pop();
	bool isEmpty();
};

