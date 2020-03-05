#include <iostream>
#include <vector>

#include "BinaryHeap.hh"

constexpr auto g_displayer = [](auto value) -> void
{
  std::cout << value << " ";
};
  
void testCase_0()
{
  tree::BinaryHeap<int> binaryHeap;
  
  std::cout << "BinaryHeap size : " << binaryHeap.size() << std::endl;
  binaryHeap.apply(g_displayer);

  std::cout << "\n";

  
  std::cout << "( ( ( ( Reorganize ) ) ) )" << "\n\n";
  
  binaryHeap.reorganize();


  std::cout << "( ( ( ( Sort ) ) ) )" << "\n\n";
  
  binaryHeap.sort();

  
  try
    {
      std::cout << "( ( ( ( Pop ) ) ) )" << "\n\n";
      
      binaryHeap.pop();
    }
  catch (const std::out_of_range& e)
    {
      std::cout << "Exception throwed : " << e.what() << std::endl;
    }
    
  std::cout << std::endl;
  std::cout << "BinaryHeap size : " << binaryHeap.size();
}
  
void testCase_1()
{
  std::initializer_list<int> initList { 10, 20, 30, 5, 15 };
  tree::BinaryHeap<int> binaryHeap(initList);  
  
  std::cout << "( ( ( ( Constructor with 10, 20, 30, 5, 15 ) ) ) )" << "\n\n";

  std::cout << "BinaryHeap size : " << binaryHeap.size() << std::endl;
  binaryHeap.apply(g_displayer);
  
  std::cout << "\n\n\n";
  

  std::cout << "( ( ( ( Reorganize ) ) ) )" << "\n\n";
  
  binaryHeap.reorganize();
  binaryHeap.apply(g_displayer);
  
  std::cout << "\n\n\n";
  

  std::cout << "( ( ( ( Sort ) ) ) )" << "\n\n";
  
  binaryHeap.sort();
  binaryHeap.apply(g_displayer);   
}

/*

  Test Case 1


         10                             30                           5

        /  \         Reorganize        /  \           Sort          / \

      20    30     ------------->    15    20     ----------->    10   15

     /  \                           /  \                         /  \

    5    15                        5    10                     20    30

*/



     

void testCase_2()
{
  tree::BinaryHeap<int> binaryHeap;

  std::cout << "( ( ( ( Push 12 ) ) ) )" << "\n\n";

  binaryHeap.push(12);


  std::cout << "BinaryHeap size : " << binaryHeap.size() << std::endl;
  binaryHeap.apply(g_displayer);

  std::cout << "\n\n\n";


  std::cout << "( ( ( ( Reorganize ) ) ) " << "\n\n";

  binaryHeap.reorganize();
  binaryHeap.apply(g_displayer);

  std::cout << "\n\n\n";
  
  
  std::cout << "( ( ( ( Sort ) ) ) )" << "\n\n";

  binaryHeap.sort();
  binaryHeap.apply(g_displayer);

  std::cout << "\n\n\n";
  
  
  std::cout << "( ( ( ( Reorganize ) ) )" << "\n\n";

  binaryHeap.reorganize();
  binaryHeap.apply(g_displayer);

  std::cout << "\n\n\n";


  std::cout << "( ( ( ( Push 42 ) ) )" << "\n\n";

  binaryHeap.push(42);


  std::cout << "BinaryHeap size : " << binaryHeap.size() << std::endl;
  binaryHeap.apply(g_displayer);

  std::cout << "\n\n\n";


  std::cout << "( ( ( ( Sort ) ) ) )" << "\n\n";

  binaryHeap.sort();
  binaryHeap.apply(g_displayer);

  std::cout << "\n\n\n";
  
  
  std::cout << "( ( ( ( Reorganize ) ) )" << "\n\n";

  binaryHeap.reorganize();
  binaryHeap.apply(g_displayer);

  std::cout << "\n\n\n";


  std::cout << "( ( ( ( Pop 42 ) ) ) )" << "\n\n";

  binaryHeap.pop();


  std::cout << "BinaryHeap size : " << binaryHeap.size() << std::endl;
  binaryHeap.apply(g_displayer);
}

/*

  Test Case 2


  12                 42               12                     42            12

       Push 42      /     Sort       /      Reorganize      /     Pop 42

      ------->    12     ----->    42       --------->    12      ----->

*/




void testCase_3()
{
  tree::BinaryHeap<int> binaryHeap;

  std::cout << "( ( ( ( Push 42, 1, 28, 95, 8, 14, 60 ) ) ) )" << "\n\n";

  binaryHeap.push(42);
  binaryHeap.push(1);
  binaryHeap.push(28);
  binaryHeap.push(95);
  binaryHeap.push(8);
  binaryHeap.push(14);
  binaryHeap.push(60);

  std::cout << "BinaryHeap size : " << binaryHeap.size() << std::endl;
  binaryHeap.apply(g_displayer);

  std::cout << "\n\n\n";

  
  std::cout << "( ( ( ( Pop 95 ) ) ) )" << "\n\n";

  binaryHeap.pop();

  std::cout << "BinaryHeap size : " << binaryHeap.size() << std::endl;
  binaryHeap.apply(g_displayer);

  std::cout << "\n\n\n";


  std::cout << "( ( ( ( Pop 60 ) ) ) )" << "\n\n";

  binaryHeap.pop();

  std::cout << "BinaryHeap size : " << binaryHeap.size() << std::endl;
  binaryHeap.apply(g_displayer);

  std::cout << "\n\n\n";


  std::cout << "( ( ( ( Pop 42 ) ) ) )" << "\n\n";

  binaryHeap.pop();

  
  std::cout << "BinaryHeap size : " << binaryHeap.size() << std::endl;
  binaryHeap.apply(g_displayer);

  std::cout << "\n\n\n";


  std::cout << "( ( ( ( Push 20 ) ) ) )" << "\n\n";

  binaryHeap.push(20);

  
  std::cout << "BinaryHeap size : " << binaryHeap.size() << std::endl;
  binaryHeap.apply(g_displayer);

  std::cout << "\n\n\n";


  std::cout << "( ( ( ( Push 3 ) ) ) )" << "\n\n";

  binaryHeap.push(3);

  
  std::cout << "BinaryHeap size : " << binaryHeap.size() << std::endl;
  binaryHeap.apply(g_displayer);

  std::cout << "\n\n\n";


  std::cout << "( ( ( ( Reorganize ) ) ) )" << "\n\n";

  binaryHeap.reorganize();  
  binaryHeap.apply(g_displayer);
}

/*

  Test Case 3


       95                      60                 42                  28

      /  \        Pop 95      /  \     Pop 60    /  \     Pop 42     /  \

   42      60      --->    42      28   --->   14    28    --->    14    8

  /  \    /  \            /  \    /           /  \                /  

 1    8 14    28         1    8 14           1    8              1



               28                     28

  Push 20     /  \      Push 3       /  \

   --->     20    8      --->     20      8

           /  \                  /  \    /

          1    14               1    14 3

*/




void testCase_4()
{
  std::initializer_list<int> initList { 28, 49, 3 };
  
  // Tas-Min with std::greater comparator
  tree::BinaryHeap<int, std::greater<int>> binaryHeap(initList);

  std::cout << "( ( ( ( Construtor with 28, 49, 3 ) ) ) )" << "\n\n"; 

  std::cout << "BinaryHeap size : " << binaryHeap.size() << std::endl;
  binaryHeap.apply(g_displayer);

  std::cout << "\n\n\n";


  std::cout << "( ( ( ( Reorganize ) ) ) )" << "\n\n";

  binaryHeap.reorganize();
  binaryHeap.apply(g_displayer);

  std::cout << "\n\n\n";


  std::cout << "( ( ( ( Push 9 ) ) ) )" << "\n\n";
  
  binaryHeap.push(9);


  std::cout << "BinaryHeap size : " << binaryHeap.size() << std::endl;
  binaryHeap.apply(g_displayer);

  std::cout << "\n\n\n";


  std::cout << "( ( ( ( Push 0 ) ) ) )" << "\n\n";

  binaryHeap.push(0);


  std::cout << "BinaryHeap size : " << binaryHeap.size() << std::endl;
  binaryHeap.apply(g_displayer);

  std::cout << "\n\n\n";


  std::cout << "( ( ( ( Push 10 ) ) ) )" << "\n\n";

  binaryHeap.push(10);


  std::cout << "BinaryHeap size : " << binaryHeap.size() << std::endl;
  binaryHeap.apply(g_displayer);

  std::cout << "\n\n\n";


  std::cout << "( ( ( ( Pop 0 ) ) ) )" << "\n\n";

  binaryHeap.pop();


  std::cout << "BinaryHeap size : " << binaryHeap.size() << std::endl;
  binaryHeap.apply(g_displayer);

  std::cout << "\n\n\n";


  std::cout << "( ( ( ( Pop 3 ) ) ) )" << "\n\n";

  binaryHeap.pop();

  
  std::cout << "BinaryHeap size : " << binaryHeap.size() << std::endl;
  binaryHeap.apply(g_displayer);

  std::cout << "\n\n\n";


  std::cout << "( ( ( ( Sort ) ) ) " << "\n\n";
  
  binaryHeap.sort();
  binaryHeap.apply(g_displayer);
}

/*

  Test Case 4 (Tas-min)


      28      Reorganize      3       Push 9      3       Push 0       0
               
     /  \     ---------->   /   \     ------>   /   \     ------>    /   \

   49    3                49     28            9     28             3     28

                                              /                   /   \

                                            49                  49     9



 Push 10       0        Pop 0      3        Pop 3      9       Sort      49

 ------>     /   \      ---->    /   \      ---->    /   \     ---->    /  \

           3      10            9     10            28    10          28    10

         /   \   /            /   \                /                 /

       49     9 28          49     28             49                9

*/




void startTests(std::vector<void (*)()> testCaseVect)
{
  for (std::uint32_t i = 0; i < testCaseVect.size(); ++i)
    {
      std::cout << "[Start of testCase " << i << "]" << "\n\n\n";
      testCaseVect.at(i)();
      std::cout << "\n\n\n"
		<< "[End of testCase "
		<< i
		<< "]"
		<< "\n\n"
		<< "----------------------------------------------------------"
		<< "\n";
    }
}

int main()
{
  startTests
    ({
      &testCase_0,
      &testCase_1,
      &testCase_2,
      &testCase_3,
      &testCase_4
    });
  return 0;
}
 
