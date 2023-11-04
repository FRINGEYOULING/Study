//
// Created by 22755 on 2023/1/29.
//

#ifndef UNTITLED_CURA_H
#define UNTITLED_CURA_H
#define WIDTH  120   // 图像宽度
#define HEIGHT 188   // 图像高度
#define THRESHOLD 100 // 二值化阈值
struct ListNode {
    int val;
    struct ListNode *next;
};

#include "stdbool.h"

__attribute__((unused)) int search(const int *nums, int numsSize, int target);//二分查找
int searchInsert(const int *nums, int numsSize, int target);//搜索插入
int *twoSum(int *numbers, int numbersSize, int target, int *returnSize);//双指针计算两数之和
int lengthOfLongestSubstring(char *s);//无重复字符的最长字串
double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2, int nums2Size);//找中位数
int *sortedSquares(int *nums, int numsSize, int *returnSize);//平方排序
void rotate(int *nums, int numsSize, int k);//轮转
void moveZeroes(int *nums, int numsSize);//移动0到末尾
char *longestPalindrome(char *s);//最长回文字
void reverseString(char *s, int sSize);//轮转字符
char *reverseWords(char *s);//轮转语句
int countAsterisks(char *s);//统计星号
int reverse(int x);//反转整数
int floodFill(int imageSize, int sr, int sc, int color);

bool containsDuplicate(int *nums, int numsSize);

int process();

#endif //UNTITLED_CURA_H
