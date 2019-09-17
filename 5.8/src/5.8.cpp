
#include <iostream>
#include <string.h>
using namespace std;

void Inc(int* x, int val)
{
	*x += val;
}

int main()
{
	int i_inc = 0;
	int p_inc = 0;

	char str[] = "This is test string!";

	for (unsigned int i = 0; str[i] != '\0'; i++)
	{
		Inc(&i_inc, str[i]);
	}

	for (char* p = &str[0]; *p != '\0'; p++)
	{
		Inc(&p_inc, *p);
	}

	cout << "p: " << p_inc << "\n";
	cout << "i: " << i_inc << "\n";

	return 0;
}


/*
The following code can be viewed by using the Eclipse "disassembly" view.
Executie:
	Run >> Debug.
	Window >> Show View >> Disassembly

18        	for (unsigned int i = 0; str[i] != '\0'; i++)
00401470:   movl    $0x0,-0xc(%ebp)
00401477:   lea     -0x2d(%ebp),%edx
0040147a:   mov     -0xc(%ebp),%eax
0040147d:   add     %edx,%eax
0040147f:   movzbl  (%eax),%eax
00401482:   test    %al,%al
00401484:   je      0x4014a9 <main()+132>
20        		Inc(&i_inc, str[i]);
00401486:   lea     -0x2d(%ebp),%edx
00401489:   mov     -0xc(%ebp),%eax
0040148c:   add     %edx,%eax
0040148e:   movzbl  (%eax),%eax
00401491:   movsbl  %al,%eax
00401494:   mov     %eax,0x4(%esp)
00401498:   lea     -0x14(%ebp),%eax
0040149b:   mov     %eax,(%esp)
0040149e:   call    0x401410 <Inc(int*, int)>
18        	for (unsigned int i = 0; str[i] != '\0'; i++)
004014a3:   addl    $0x1,-0xc(%ebp)
004014a7:   jmp     0x401477 <main()+82>


23        	for (char* p = &str[0]; *p != '\0'; p++)
004014a9:   lea     -0x2d(%ebp),%eax
004014ac:   mov     %eax,-0x10(%ebp)
004014af:   mov     -0x10(%ebp),%eax
004014b2:   movzbl  (%eax),%eax
004014b5:   test    %al,%al
004014b7:   je      0x4014d7 <main()+178>
25        		Inc(&p_inc, *p);
004014b9:   mov     -0x10(%ebp),%eax
004014bc:   movzbl  (%eax),%eax
004014bf:   movsbl  %al,%eax
004014c2:   mov     %eax,0x4(%esp)
004014c6:   lea     -0x18(%ebp),%eax
004014c9:   mov     %eax,(%esp)
004014cc:   call    0x401410 <Inc(int*, int)>
23        	for (char* p = &str[0]; *p != '\0'; p++)
004014d1:   addl    $0x1,-0x10(%ebp)
004014d5:   jmp     0x4014af <main()+138>

====

As can be seen the code looks disassembly looks pretty similar but is slightly different.
I'm not doing to the effort of decoding the disassembly but the different in operators likely
point to array indexing (i.e. loading the correct address from the array) in the first case,
where this isn't needed if using the pointer.

This was only executed with the default optimization level.

*/
