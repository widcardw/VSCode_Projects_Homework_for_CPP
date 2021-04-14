#include <iostream>
#include <fstream>
#include <iomanip>
void ShellSort(int *arr, int start, int end)
{
    int n = end - start + 1, d, i, j, temp;
    for (d = n / 2; d >= 1; d /= 2)
    {
        for (i = d; i <= end; ++i)
        {
            temp = arr[i];
            for (j = i - d; j >= start && temp < arr[j]; j -= d)
            {
                arr[j + d] = arr[j];
            }
            arr[j + d] = temp;
        }
    }
}

int Partition(int *arr, int i, int j)
{
    int temp = arr[i];
    while (i < j)
    {
        while (i < j && arr[j] >= temp)
            --j;
        if (i < j)
        {
            arr[i] = arr[j];
            ++i;
        }
        while (i < j && arr[i] <= temp)
            ++i;
        if (i < j)
        {
            arr[j] = arr[i];
            --j;
        }
    }
    arr[i] = temp;
    return i;
}
void QuickSort(int *arr, int start, int end)
{
    if (start < end)
    {
        int pivot = Partition(arr, start, end);
        QuickSort(arr, start, pivot - 1);
        QuickSort(arr, pivot + 1, end);
    }
}

void swap(int *arr, int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
void Sift(int *arr, int k, int m)
{
    int i = k;         // the node
    int j = 2 * i + 1; // lchild index of the node
    while (j <= m)
    {
        if (j < m && arr[j] < arr[j + 1])
            ++j;
        if (arr[i] > arr[j]) // value of the node is greater than value of children
            break;
        else
        {
            swap(arr, i, j);
            i = j; // Here may be some error
            j = 2 * i + 1;
        }
    }
}
void HeapSort(int *arr, int start, int end)
{
    int n = end - start + 1, i;
    for (i = n / 2 - 1; i >= 0; --i)
        Sift(arr, i, n - 1);
    for (i = n - 1; i > 0; --i)
    {
        swap(arr, 0, i);
        Sift(arr, 0, i - 1);
    }
}

void merge(int arr1[], int arr2[], int start, int mid, int end)
{
    int i = start, j = mid + 1, k = start;
    while (i <= mid && j <= end)
        if (arr1[i] < arr1[j])
            arr2[k++] = arr1[i++];
        else 
            arr2[k++] = arr1[j++];
    if (i <= mid)
        while (i <= mid)
            arr2[k++] = arr1[i++];
    else 
        while (j <= end)
            arr2[k++] = arr1[j++];
}
void mergePass(int arr1[], int arr2[], int n, int h)
{
    int i = 1;
    while (i <= n - 2 * h + 1)
    {
        merge(arr1, arr2, i, i + h - 1, i + 2 * h - 1);
        i += 2 * h;
    }
    if (i < n - h + 1)
    {
        merge(arr1, arr2, i, i + h - 1, n);
    }
    else{
        for (int k = i; k <= n; ++k)
            arr2[k] = arr1[k];
    }
}
void MergeSort1(int arr1[], int arr2[], int start, int end)
{
    int h = 1, n = end - start + 1;
    while (h < n)
    {
        mergePass(arr1, arr2, n, h);
        h *= 2;
        mergePass(arr2, arr1, n, h);
        h *= 2;
    }
}
void MergeSort2(int arr1[], int arr2[], int arr3[], int start, int end)
{
    if (start == end) arr2[start] = arr1[start];
    else{
        int m = (start + end) / 2;
        MergeSort2(arr1, arr3, arr2, start, m);
        MergeSort2(arr1, arr3, arr2, m+1, end);
        merge(arr3, arr2, start, m, end);
    }
}


void generateRandomNumbers(int n) 
{
    srand(time(NULL));
    int range = n, i;
    std::ofstream file;
    file.open("random.dat");
    if (!file)
    {
        std::cerr << "Cannot open file!";
        exit(-1);
    }
    for (i = 0; i < range; ++i)
    {
        file << rand() % 998244353;
        if (i % 20 == 19)
            file << '\n';
        else
            file << '\t';
    }
    file.close();
    std::cout << "随机数已存放到 random.dat 文件中" << std::endl;
}

void execShellSort(int n, std::ifstream& fin, std::ofstream& fout) 
{
    fin.open("random.dat");
    if (!fin) 
    {
        std::cerr << "Cannot open the file!";
        exit(-1);
    }
    int arr[10000] = {0}, i = 0;
    while (fin >> arr[i++]) ;
    fin.close();
    ShellSort(arr, 0, n - 1);
    fout.open("ShellSort.dat");
    if (!fout)
    {
        std::cerr << "Cannot open file!";
        exit(-1);
    }
    for (i = 0; i < n; ++i)
    {
        fout << std::setw(10) << arr[i];
        if (i % 10 == 9)
            fout << '\n';
    }
    fout.close();
    std::cout << "Shell sort Finish!" << std::endl;
}

void execQuickSort(int n, std::ifstream& fin, std::ofstream& fout) 
{
    fin.open("random.dat");
    if (!fin) 
    {
        std::cerr << "Cannot open the file!";
        exit(-1);
    }
    int arr[10000] = {0}, i = 0;
    while (fin >> arr[i++]) ;
    fin.close();
    QuickSort(arr, 0, n - 1);
    fout.open("QuickSort.dat");
    if (!fout)
    {
        std::cerr << "Cannot open file!";
        exit(-1);
    }
    for (i = 0; i < n; ++i)
    {
        fout << std::setw(10) << arr[i];
        if (i % 10 == 9)
            fout << '\n';
    }
    fout.close();
    std::cout << "Quick sort Finish!" << std::endl;
}

void execHeapSort(int n, std::ifstream& fin, std::ofstream& fout) 
{
    fin.open("random.dat");
    if (!fin) 
    {
        std::cerr << "Cannot open the file!";
        exit(-1);
    }
    int arr[10000] = {0}, i = 0;
    while (fin >> arr[i++]) ;
    fin.close();
    HeapSort(arr, 0, n - 1);
    fout.open("HeapSort.dat");
    if (!fout)
    {
        std::cerr << "Cannot open file!";
        exit(-1);
    }
    for (i = 0; i < n; ++i)
    {
        fout << std::setw(10) << arr[i];
        if (i % 10 == 9)
            fout << '\n';
    }
    fout.close();
    std::cout << "Heap sort Finish!" << std::endl;
}

void execMergeSort(int n, std::ifstream& fin, std::ofstream& fout) 
{
    fin.open("random.dat");
    if (!fin) 
    {
        std::cerr << "Cannot open the file!";
        exit(-1);
    }
    int arr[10000] = {0}, i = 0;
    int arr2[10000], arr3[10000];
    while (fin >> arr[i++]) ;
    fin.close();
    MergeSort2(arr, arr2, arr3, 0, n - 1);
    fout.open("MergeSort.dat");
    if (!fout)
    {
        std::cerr << "Cannot open file!";
        exit(-1);
    }
    for (i = 0; i < n; ++i)
    {
        fout << std::setw(10) << arr2[i];
        if (i % 10 == 9)
            fout << '\n';
    }
    fout.close();
    std::cout << "Merge sort Finish!" << std::endl;
}

void test() 
{
    std::ifstream fin;
    std::ofstream fout;
    const int N = 10000;
    while(1)
    {
        std::cout << "*******************" << std::endl;
        std::cout << "1.生成随机数" << std::endl;
        std::cout << "2.希尔排序" << std::endl;
        std::cout << "3.快速排序" << std::endl;
        std::cout << "4.堆排序" << std::endl;
        std::cout << "5.归并排序" << std::endl;
        std::cout << "6.退出" << std::endl;
        std::cout << "请选择：";
        int choice = 0;
        std::cin >> choice;
        switch (choice) 
        {
            case 1:
            {
                generateRandomNumbers(N);
                break;
            }
            case 2:
            {
                execShellSort(N, fin, fout);
                break;
            }
            case 3:
            {
                execQuickSort(N, fin, fout);
                break;
            }
            case 4:
            {
                execHeapSort(N, fin, fout);
                break;
            }
            case 5:
            {
                execMergeSort(N, fin, fout);
                break;
            }
            default:
                exit(0);
        }
    }
}

int main()
{
    test();
    // std::ifstream fin;
    // std::ofstream fout;
    // {
    //     fin.open("data.dat");
    //     if (!fin)
    //     {
    //         std::cerr << "Cannot open file!";
    //         exit(-1);
    //     }
    //     int x = 0, arr[10000] = {0}, i = 0;
    //     while (fin >> x)
    //     {
    //         arr[i++] = x;
    //     }
    //     fin.close();
    //     HeapSort(arr, 0, 9999);
    //     fout.open("Heap.dat");
    //     if (!fout)
    //     {
    //         std::cerr << "Cannot open file!";
    //         exit(-1);
    //     }
    //     for (i = 0; i < 10000; ++i)
    //     {
    //         fout << std::setw(10) << arr[i];
    //         if (i % 10 == 9)
    //             fout << '\n';
    //     }
    //     fout.close();
    //     std::cout << "Heap sort Finish!" << std::endl;
    // }
    // {
    //     fin.open("data.dat");
    //     if (!fin)
    //     {
    //         std::cerr << "Cannot open file!";
    //         exit(-1);
    //     }
    //     int x = 0, arr[10000] = {0}, i = 0;
    //     while (fin >> x)
    //     {
    //         arr[i++] = x;
    //     }
    //     fin.close();
    //     QuickSort(arr, 0, 9999);
    //     fout.open("QuickSort.dat");
    //     if (!fout)
    //     {
    //         std::cerr << "Cannot open file!";
    //         exit(-1);
    //     }
    //     for (i = 0; i < 10000; ++i)
    //     {
    //         fout << std::setw(10) << arr[i];
    //         if (i % 10 == 9)
    //             fout << '\n';
    //     }
    //     fout.close();
    //     std::cout << "Quick sort Finish!" << std::endl;
    // }
    // {
    //     fin.open("data.dat");
    //     if (!fin)
    //     {
    //         std::cerr << "Cannot open file!";
    //         exit(-1);
    //     }
    //     int x = 0, arr[10000] = {0}, i = 0;
    //     while (fin >> x)
    //     {
    //         arr[i++] = x;
    //     }
    //     fin.close();
    //     ShellSort(arr, 0, 9999);
    //     fout.open("Shell.dat");
    //     if (!fout)
    //     {
    //         std::cerr << "Cannot open file!";
    //         exit(-1);
    //     }
    //     for (i = 0; i < 10000; ++i)
    //     {
    //         fout << std::setw(10) << arr[i];
    //         if (i % 10 == 9)
    //             fout << '\n';
    //     }
    //     fout.close();
    //     std::cout << "Shell sort Finish!" << std::endl;
    // }
    // {
    //     fin.open("data.dat");
    //     if (!fin)
    //     {
    //         std::cerr << "Cannot open file!";
    //         exit(-1);
    //     }
    //     int x = 0, arr[10000] = {0}, i = 0;
    //     while (fin >> x)
    //     {
    //         arr[i++] = x;
    //     }
    //     fin.close();
    //     int arr2[10000], arr3[10000];
    //     MergeSort2(arr, arr2, arr3, 0, 9999);
    //     fout.open("Merge.dat");
    //     if (!fout)
    //     {
    //         std::cerr << "Cannot open file!";
    //         exit(-1);
    //     }
    //     for (i = 0; i < 10000; ++i)
    //     {
    //         fout << std::setw(10) << arr2[i];
    //         if (i % 10 == 9)
    //             fout << '\n';
    //     }
    //     fout.close();
    //     std::cout << "Merge sort Finish!" << std::endl;
    // }
    return 0;
}