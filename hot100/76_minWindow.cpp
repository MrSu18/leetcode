#include <vector>
#include <iostream>

using namespace std;

class Solution 
{
public:
    bool isCoverStr(int cnt_s[],int cnt_t[]) //判断s是否包括t
    {
        for (int i = 'A'; i <= 'Z'; i++)
        {
            if (cnt_t[i]>cnt_s[i])
            {
                return false;
            }
            
        }
        for (int i = 'a'; i <= 'z'; i++)
        {
            if (cnt_s[i]<cnt_t[i])
            {
                return false;
            }
            
        }
        return true;
    }
    string minWindow(string s, string t) 
    {
        int cnt_t[128]={0};
        int cnt_s[128]={0};
        for (char c : t) //给cnt_t赋值
        {
            cnt_t[c]++;
        }
        
        int len=s.size();
        int re_left = -1,re_right = len;
        int l=0,r=0;//滑动窗口的双指针
        for (; r < len; r++)
        {
            cnt_s[s[r]]++;//记录字母出现的次数
            while (isCoverStr(cnt_s,cnt_t))//判断现在的窗口是否涵盖了目标子串
            {
                if (re_right-re_left>r-l)//更新
                {
                    re_left=l;
                    re_right=r;
                }
                //如果涵盖了试着缩小
                cnt_s[s[l]]--;l++;
            }
            
        }
        return re_left < 0 ? "" : s.substr(re_left, re_right - re_left + 1);
    }
};

int main ()
{
    string s = "wegdtzwabazduwwdysdetrrctotpcepalxdewzezbfewbabbseinxbqqplitpxtcwwhuyntbtzxwzyaufihclztckdwccpeyonumbpnuonsnnsjscrvpsqsftohvfnvtbphcgxyumqjzltspmphefzjypsvugqqjhzlnylhkdqmolggxvneaopadivzqnpzurmhpxqcaiqruwztroxtcnvhxqgndyozpcigzykbiaucyvwrjvknifufxducbkbsmlanllpunlyohwfsssiazeixhebipfcdqdrcqiwftutcrbxjthlulvttcvdtaiwqlnsdvqkrngvghupcbcwnaqiclnvnvtfihylcqwvderjllannflchdklqxidvbjdijrnbpkftbqgpttcagghkqucpcgmfrqqajdbynitrbzgwukyaqhmibpzfxmkoeaqnftnvegohfudbgbbyiqglhhqevcszdkokdbhjjvqqrvrxyvvgldtuljygmsircydhalrlgjeyfvxdstmfyhzjrxsfpcytabdcmwqvhuvmpssingpmnpvgmpletjzunewbamwiirwymqizwxlmojsbaehupiocnmenbcxjwujimthjtvvhenkettylcoppdveeycpuybekulvpgqzmgjrbdrmficwlxarxegrejvrejmvrfuenexojqdqyfmjeoacvjvzsrqycfuvmozzuypfpsvnzjxeazgvibubunzyuvugmvhguyojrlysvxwxxesfioiebidxdzfpumyon";
    string t = "ozgzyywxvtublcl";
    Solution test;
    cout<<test.minWindow(s,t)<<endl;
    return 1;
}
