# 定义输入和输出文件的路径
input_file = "test1.txt"
output_file = "test_index.txt"

# 打开输入文件和输出文件
with open(input_file, "r") as f_in, open(output_file, "w") as f_out:
    # 逐行读取输入文件中的内容
    for line in f_in:
        # 从每行中提取出数字和文件名
        parts = line.strip().split()
        num = parts[0]
        filename = parts[1]

        # 组合新的文件名
        new_filename = "./data/" + filename

        # 将修改后的行写入输出文件
        f_out.write(new_filename + "\n")
