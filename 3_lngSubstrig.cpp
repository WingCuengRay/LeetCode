class Solution
{
public:
	int lengthOfLongestSubstring(string s)
	{
		if(s.size() == 0)
			return 0;

		deque<char> que;
		map<char, deque<char>::iterator> hash;
		que.push_back(s[0]);		//队列
		hash[s[0]] = que.begin();	//哈希表

		size_t i=0;
		int max = 1;
		int cnt = 1;
		
		i = 0;
		for(size_t j=1; j<s.size(); j++)
		{
			auto search = HasAppeared(s[j], que, hash);
			if(search != que.end())		//有重复的
			{
				int num = deleteQueueElem(*search, que, hash);
				cnt = cnt+1-num;
			}
			else
			{
				cnt++;
			}

			que.push_back(s[j]);
			hash[s[j]] = que.end()-1;	//新插入的元素，即队尾元素　
			if(max < cnt)
				max = cnt;
		}
		
		return max;
	}
	
	deque<char>::iterator HasAppeared(char ch, 
						deque<char> &que, map<char, deque<char>::iterator> &hash)
	{
		auto search = hash.find(ch);
		if(search == hash.end())		//在哈希表中没有出现过
		return que.end();			//返回队列的尾后迭代器

		auto tmp = search->second;
		hash.erase(search);
		return tmp;
	}

	int deleteQueueElem(char com, deque<char> &que,map<char, deque<char>::iterator> &hash);

};

int Solution::deleteQueueElem(char com, deque<char> &que,map<char, deque<char>::iterator> &hash)
{
	int cnt = 0;

	while(que.front() != com)
	{
		char tmp = que.front();
		que.pop_front();
		hash.erase(tmp);
		cnt++;
	}
//	char tmp = que.front();
//	hash.erase(tmp);
	que.pop_front();	//将前一个相同的也出队列
	cnt++;
	
	return cnt;
}
