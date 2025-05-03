/******************************************************************************

Valid Sudoku Checker.

[5 ,- ,- ,3 ,- ,- ,- ,- ,1 ]
[- ,- ,7 ,- ,9 ,- ,- ,- ,- ]
[- ,7 ,- ,- ,- ,- ,- ,3 ,- ]
[- ,- ,- ,- ,- ,- ,- ,- ,- ]
[6 ,- ,8 ,- ,- ,- ,- ,- ,- ]
[- ,- ,- ,- ,- ,1 ,- ,- ,- ]
[3 ,- ,- ,2 ,- ,- ,- ,- ,4 ]
[- ,- ,- ,- ,- ,2 ,- ,- ,- ]
[- ,5 ,- ,- ,6 ,- ,- ,- ,- ]


*******************************************************************************/
#include <iostream>
#include <unordered_set>

using namespace std;

int sudoku[9][9] = 
{ 
    { 5 ,-1 ,-1 , 3 ,-1 ,-1 ,-1 ,-1 , 1 },
    {-1 ,-1 , 7 ,-1 , 9 ,-1 ,-1 ,-1 ,-1 },
    {-1 , 6 ,-1 , 2 ,-1 ,-1 ,-1 , 3 ,-1 },
    {-1 ,-1 ,-1 ,-1 ,-1 ,-1 ,-1 ,-1 ,-1 },
    { 6 ,-1 , 8 ,-1 ,-1 ,-1 ,-1 ,-1 ,-1 },
    {-1 ,-1 ,-1 ,-1 ,-1 , 1 ,-1 ,-1 ,-1 },
    { 3 ,-1 ,-1 , 2 ,-1 ,-1 ,-1 ,-1 , 4 },
    { 2 ,-1 ,-1 ,-1 ,-1 , 2 ,-1 ,-1 ,-1 },
    {-1 , 5 ,-1 ,-1 , 6 ,-1 ,-1 ,-1 ,-1 }
};

//We need 9 hashsets for 9 rows
bool isValidRows()
{
    for(int row = 0; row < 9; row++)
    {
        //creat a new hashset for row
        unordered_set<int> rowset;
        for(int col = 0; col < 9; col++)
        {
            if(rowset.find(sudoku[row][col]) != rowset.end())
            {
                //element exists
                cout << "Failed row validity at " << row << "," << col << endl;
                return false;
            }
            
            //Skip un-initialized entries
            if(sudoku[row][col] != -1)
            {
                rowset.insert(sudoku[row][col]);
            }
        }
    }
    
    return true;
}

//We need 9 hashsets for 9 cols
bool isValidCols()
{
    for(int col = 0; col < 9; col++)
    {
        //creat a new hashset for col
        unordered_set<int> colset;
        for(int row = 0; row < 9; row++)
        {
            if(colset.find(sudoku[row][col]) != colset.end())
            {
                //element exists
                cout << "Failed col validity at " << row << "," << col << endl;
                return false;
            }
            
            //Skip un-initialized entries
            if(sudoku[row][col] != -1)
            {
                colset.insert(sudoku[row][col]);
            }
        }
    }
    
    return true;
}

//We need 9 hashmaps for 9 - 3x3 boxes
//Hashset(id) = ((row/3) * 3) + (col % 3)
//
// The 9 boxes should have below formula
// [0+0 0+1 0+2]
// [3+0 3+1 3+2]
// [6+0 6+1 6+2]
unordered_set<int> boxSet[9];
bool isValidBoxes()
{
    int hashsetId;
    for(int row = 0; row < 9; row++)
    {
        for(int col = 0; col < 9; col++)
        {
            hashsetId =  ((row/3) * 3) + (col/3);
            if(boxSet[hashsetId].find(sudoku[row][col]) != boxSet[hashsetId].end())
            {
                //element exists
                cout << "Failed boxes validity at " << row << "," << col << endl;
                return false;
            }
            
            //Skip un-initialized entries
            if(sudoku[row][col] != -1)
            {
                boxSet[hashsetId].insert(sudoku[row][col]);
            }
        }
    }
    
    return true;
}

int main()
{
    bool check = isValidRows();
    cout << "ValidRows = " << check << endl;
    check = isValidCols();
    cout << "ValidCols = " << check << endl;
    check = isValidBoxes();
    cout << "ValidCols = " << check << endl;

    return 0;
}