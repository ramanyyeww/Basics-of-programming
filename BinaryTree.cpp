﻿#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        calculateMaxSum(root, maxSum);
        return maxSum;
    }

    int calculateMaxSum(TreeNode* node, int& maxSum) {
        if (node == nullptr) {
            return 0;
        }

        int leftMax = max(0, calculateMaxSum(node->left, maxSum));
        int rightMax = max(0, calculateMaxSum(node->right, maxSum));

        int currentMax = node->val + leftMax + rightMax;
        maxSum = max(maxSum, currentMax);

        return node->val + max(leftMax, rightMax);
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    string choice;
    static int storedResult = 0; // статическая переменная для сохранения результата

    do {
        // Создаём дерево из примера [-10,9,20,null,null,15,7]
        TreeNode* root = new TreeNode(-10);
        root->left = new TreeNode(9);
        root->right = new TreeNode(20);
        root->right->left = new TreeNode(15);
        root->right->right = new TreeNode(7);

        // Используем статическую переменную, если она уже была заполнена ранее
        int result;
        if (storedResult != 0) {
            result = storedResult;
        }
        else {
            Solution solution;
            result = solution.maxPathSum(root);
            storedResult = result; // сохраняем результат в статической переменной
        }
        cout << "Результат: " << result << endl;

        // Очищаем память, выделенную под дерево
        delete root->right->right;
        delete root->right->left;
        delete root->right;
        delete root->left;
        delete root;

        cout << "Запустить снова? (y/n): ";
        cin >> choice;
    } while (choice == "Y" || choice == "y");
    return 0;
}
