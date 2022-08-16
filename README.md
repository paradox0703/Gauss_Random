# Drone-UE / 森林生成
## 高斯分布+随机分布
### 1. 内含功能：
    森林中树木的高度（高斯分布）
    森林中树木的直径（高斯分布）
    森林中树木的位置（二维坐标/随机分布）

### 2. 函数：
    #### Gauss_Height(double* Height, int Amount)
    -- Parameters:
        Height:用于存储各树木高度
        Amount：树木数量
    -- explain：
        *调用时需引入已定义的Height数组参数
        *功能为在Height数组中写入呈高斯分布的高度数据
        *待提升：可以让用户手动填写树高度的均值和方差
    #### Gauss_Diameter(double* Diameter, int Amount)
    -- Parameters:
        Diameter:用于存储各树木直径
        Amount：树木数量
    -- explain：
        *调用时需引入已定义的Diameter数组参数
        *功能为在Diameter数组中写入呈高斯分布的直径数据
        *待提升：可以让用户手动填写直径的均值和方差
    #### Random_Position_Rectangle(double* w, double* q, int Amount, float length, float width)
    -- Parameters:
        w:X坐标数组
        q:y坐标数组
        Amount:树木数量
        length:长方形的长
        width：长方形的宽
    -- explain：
        *调用时需引入已定义的x，y坐标数组参数
        *功能为在w,q数组中写入符合长方形的随机分布的位置坐标
        *待提升：现在是用穷举法判断与任意树木距离，后续可以改成其他方法提升效率（因目前的生成体量效率尚可，但可提升）
    #### Random_Position_Square(double* w, double* q, int Amount, float length)
    -- Parameters:
        w:X坐标数组
        q:y坐标数组
        Amount:树木数量
        length:正方形的边长
    -- explain：
        *调用时需引入已定义的x，y坐标数组参数
        *功能为在w,q数组中写入符合正方形的随机分布的位置坐标
        *待提升：现在是用穷举法判断与任意树木距离，后续可以改成其他方法提升效率（因目前的生成体量效率尚可，但可提升）
    #### Random_Position_Circle(double* w, double* q, int Amount, double radius)
    -- Parameters:
        w:X坐标数组
        q:y坐标数组
        Amount:树木数量
        length:圆形的半径
    -- explain：
        *调用时需引入已定义的x，y坐标数组参数
        *功能为在w,q数组中写入符合圆形的随机分布的位置坐标
        *待提升：现在是用穷举法判断与任意树木距离，后续可以改成其他方法提升效率（因目前的生成体量效率尚可，但可提升）
            
    