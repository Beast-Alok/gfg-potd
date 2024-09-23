



class Solution {

  public:

    vector<int> findTwoElement(vector<int>& arr) {

        

unordered_map<int, int> temp;

        vector<int> res;

        res.push_back(0);

        res.push_back(0);

        for(int i=0; i<arr.size(); i++)

        {

            if(temp.find(arr[i]) == temp.end() )

            {

                temp[arr[i]] = 1;

            }

            else

            {

                temp[arr[i]] += 1; // repeating element

                res[0] = arr[i];

            }

        }

        for(int i=1; i<=arr.size(); i++)

        {

            if(temp.find(i) == temp.end()) // missing element

            {

              res[1] = i;

              break;

            }

        }

         return res;



    }

};

