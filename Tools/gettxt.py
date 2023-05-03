import numpy as np
import os

# 循环遍历每个文件夹
for folder in os.listdir(os.getcwd()):
    if folder.endswith(".r2d2.result"):
        # 获取当前文件夹路径
        folder_path = os.path.join(".", folder)

        # 遍历文件夹中的文件
        for file in os.listdir(folder_path):
        # 判断是否为npy文件
            if file.endswith("keypoints.npy"):
                # 获取npy文件路径
                npy_path = os.path.join(folder_path, file)

                # 读取npy文件中的数组
                arr = np.load(npy_path)

                # 获取同名的txt文件路径
                txt_path = os.path.splitext(npy_path)[0] + ".txt"

                # 将数组写入txt文件
                with open(txt_path, "w") as f:
                    for row in arr:
                        i = 0
                        for item in row:
                            i += 1
                            f.write(str(item) + " ")
                            if i == 2:
                                break
                        f.write("\n")
