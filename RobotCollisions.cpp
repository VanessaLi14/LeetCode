class Solution {
public:
    struct SRobot
    {
        int index;
        int position;
        int health;
        char direction;
    };
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<SRobot> robots(n);

        // Step0. put into robots vector
        for (int index = 0 ; index < n ; index++)
            robots[index] = {index, positions[index], healths[index], directions[index]};

        // Step1. reorder by position
        sort(robots.begin(), robots.end(), [](const SRobot& front, const SRobot& back)
        {
            return front.position < back.position;
        });

        // Step2. collide (do by stack)
        vector<SRobot> retain_robot;
        stack<SRobot> temp_stack;
        for (auto& robot : robots)
        {
            if (robot.direction == 'R')
                temp_stack.push(robot);
            else // handle cllide events
            {
                while (!temp_stack.empty() && robot.health > 0)
                {
                    SRobot& need_pk_robot = temp_stack.top();
                    if (need_pk_robot.health > robot.health)
                    {
                        need_pk_robot.health--;
                        robot.health = 0;
                    }
                    else if (need_pk_robot.health < robot.health)
                    {
                        robot.health --;
                        temp_stack.pop();
                    }
                    else
                    {
                        robot.health = 0;
                        temp_stack.pop();
                    }
                }
                if (robot.health > 0)
                    retain_robot.emplace_back(robot);
            }
        }

        // Step3. add vector and remain stack
        while (!temp_stack.empty())
        {
            retain_robot.emplace_back(temp_stack.top());
            temp_stack.pop();
        }

        // Step4. reorder by index
        sort(retain_robot.begin(), retain_robot.end(), [](const SRobot& front, const SRobot& back)
        {
            return front.index < back.index;
        });

        // Step5. result vec<int>
        vector<int> result;
        for(auto& robot : retain_robot)
            result.emplace_back(robot.health);

        return result; 
    }
};
