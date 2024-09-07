#include "utils/head.h"
/*
380. O(1) 时间插入、删除和获取随机元素

实现RandomizedSet 类：

RandomizedSet() 初始化 RandomizedSet 对象
bool insert(int val) 当元素 val 不存在时，向集合中插入该项，并返回 true ；否则，返回 false 。
bool remove(int val) 当元素 val 存在时，从集合中移除该项，并返回 true ；否则，返回 false 。
int getRandom() 随机返回现有集合中的一项（测试用例保证调用此方法时集合中至少存在一个元素）。每个元素应该有 相同的概率 被返回。
你必须实现类的所有函数，并满足每个函数的 平均 时间复杂度为 O(1) 。
*/
class RandomizedSet {
private:
    // val -> index
    unordered_map<int, int> indexs;
    // val
    vector<int> nums;
public:
    RandomizedSet() {
        srand((unsigned)time(NULL)); // 这是C++旧方式，更推荐使用<random>
    }

    bool insert(int val) {
        if (indexs.count(val)) {
            return false;
        }
        indexs[val] = nums.size();
        nums.push_back(val);
        return true;
    }

    bool remove(int val) {
        if (indexs.count(val)) {
            int index = indexs[val];
            // 最后一个元素，覆盖删除元素下表
            int last = nums.back();
            nums[index] = last;
            // 更新最后一个元素对应的索引
            indexs[last] = index;
            nums.pop_back();
            indexs.erase(val);
            return true;
        }
        return false;
    }

    int getRandom() {
        int randomIndex = rand() % nums.size();
        return nums[randomIndex];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */