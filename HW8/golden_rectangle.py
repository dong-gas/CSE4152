import numpy as np    

class GoldenRectangle:
    def __init__(self, n):
        self.fibonacci_list = self.fibo(n)

    @staticmethod
    def fibo(n):
        # TODO: Implement Fibonacci sequence generation for problem 8-1
        if n == 1 :
            return (1, [1])
        results_list = [1, 1]
        for i in range (2, n) :
            results_list.append(results_list[i - 2] +results_list[i - 1])
        
        return results_list
    
    @staticmethod
    def right_operation(grid_cells, cur_rect_length, height, width):
        # TODO: Implement the right operation to fill the grid
        return grid_cells

    @staticmethod
    def down_operation(grid_cells, cur_rect_length, height, width):
        # TODO: Implement the down operation to fill the grid
        return grid_cells
    
    @staticmethod
    def left_operation(grid_cells, cur_rect_length, height, width):
        # TODO: Implement the left operation to fill the grid
        return grid_cells

    @staticmethod
    def up_operation(grid_cells, cur_rect_length, height, width):
        # TODO: Implement the up operation to fill the grid
        return grid_cells

    # Do not change this function name (get_golden_rectangle)
    def get_golden_rectangle(self):
        # TODO: Implement the logic to create the golden rectangle grid
        height, width = self.fibonacci_list[-1], self.fibonacci_list[-1] + self.fibonacci_list[-2]  
        grid_cells = np.zeros((height, width))  #0으로 초기화

        my_list = self.fibonacci_list[::-1]
        my_list.append(0)
        x, y, dir = 0, 0, 0

        for i in range(len(my_list) - 1):             
            f = my_list[i]
            nf = my_list[i + 1]
            # f: 피보나치 수
            grid_cells[x : x + f, y : y + f] = f
            if nf == 0 :
                break
            if dir == 0 :
                y = y + f
            elif dir == 1 :
                x = x + f
                y = y + f - nf
            elif dir == 2 :
                x = x + f - nf
                y = y - nf
            elif dir == 3 :
                x = x - nf
            dir = (dir + 1) % 4;

        # Return the grid cells as an (H, W) ndarray
        return grid_cells
        
        
# Instructions: Complete only the class implementation. You may add print statements to test when using the "Run" button, 
# but only the class will be used for grading upon submission.

n = 7
golden_rectangle_instance = GoldenRectangle(n)
golden_rectangle = golden_rectangle_instance.get_golden_rectangle()
print(golden_rectangle)

# Explanation on the difference with @staticmethod:
# Using @staticmethod:
#   - Methods marked with @staticmethod do not need access to any instance-specific data, 
#     so they can be called directly from the class, e.g., GoldenRectangle.fibo(10).
#   - They do not access self or instance variables.
# Without @staticmethod:
#   - Methods without @staticmethod need an instance of the class to access instance-specific data (like self.fibonacci_list).
#   - They are called through an instance, e.g., golden_rectangle_instance.get_golden_rectangle().

