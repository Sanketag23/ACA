class Solution {
public:
    int singleNonDuplicate(vector<int>& nms) {
        int lt = 0, rt = nms.size() - 1;

        while (lt < rt) {
            int md = lt + (rt - lt) / 2;
            if (md % 2 == 1) {
                md--;
            }

            if (nms[md] == nms[md + 1]) {
                lt = md + 2;
            } else {
                rt = md;
            }
        }

        return nms[lt];
    }
};
