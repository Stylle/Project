import requests
import os
import re

# url = 'https://www.vmgirls.com/13708.html'

# url = 'https://www.vmgirls.com/13810.html'


file_name = r'.\img'

headers = {

    'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64; rv:75.0) Gecko/20100101 Firefox/75.0',

    # 'Referer': 'https://www.vmgirls.com/13708.html'
}


def download(img_url):

    # 如果没有创建图片目录则创建
    if not os.path.exists(file_name):
        os.makedirs(file_name)

    # 图片名称
    img_name = img_url.split('/')[-1]

    # timeout = 5间接时间爬取
    f = requests.get(img_url, headers=headers, timeout=1)

    # 下载图片
    with open('{}/{}'.format(file_name, img_name), 'wb') as code:
        code.write(f.content)


def main():

    # 爬取13000---14000之间得所有图片网页

    print("数值范围越大速度越慢")

    start = input("请输入数值开始范围'12000':")

    stop = input("请输入数值结束范围'14000':")

    print('strat!!')

    i = (int(stop))-(int(start))

    for num in range(i):

        url = 'https://www.vmgirls.com/'+str(int(start)+int(num))+'.html'

        # print(num)

        html = requests.get(url, headers=headers)
        # 链接正常开始下载
        if html.status_code == 200:
            # 正则表达式提取链接和名字保存到字典
            urls = re.findall(
                '<a href="(.*?)" alt=".*?" title=".*?">', html.text)
            # 传入字典开始下载
            for item in urls:
                print(item)
                download(item)


if __name__ == '__main__':
    main()
    print('over')
