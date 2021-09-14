/*
有一部电梯，最开始停在第0层，上一层楼需要6s, 下一层楼需要4s, 每次到达当前目
的楼层还需要停留5s。现给出电梯要去的楼层的顺序， 求总共需要花费多少时间（最后不需
要同到第0层）。
*/

/*
可能会出现目的楼to就是当前层now的情况，这时根据题意，也是需要5s的停留时
间， 因此只要在每次到达目的站时都加上这个5即可。
在达到当前目的站后， 要记得把now设成该层层学。
*/
#include <iostream>
using namespace std;

int main()
{
	// total表示总共需要的时间，初值为0; 
	// now表示当前所在的层号，初值为0;
	// to表示下一个目的层号
	int n, total = 0, now = 0, to;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> to;
		if (to > now)
		{
			total += ((to - now) * 6);
		}
		else
		{
			total += ((now - to) * 4);
		}
		total += 5;
		now = to;
	}
	cout << "Total time = " << total << endl;
}