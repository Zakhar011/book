import urllib.request
import os
import sys
import re

def main():
    # Читаем переменную среды
    feed_env = os.getenv("RSS_FEED")
    if not feed_env:
        print("Ошибка: Переменная среды RSS_FEED не задана.")
        return

    # Ищем слово из аргументов (если есть)
    search_word = sys.argv[1].lower() if len(sys.argv) > 1 else ""
    
    # Книга предполагает, что в RSS_FEED может быть список через пробел
    urls = feed_env.split()

    for url in urls:
        try:
            # Маскируемся под браузер, чтобы сайты не блокировали запрос
            req = urllib.request.Request(url, headers={'User-Agent': 'Mozilla/5.0'})
            with urllib.request.urlopen(req) as response:
                content = response.read().decode('utf-8', errors='ignore')
                
                # Ищем заголовки <title> через регулярку (простой способ)
                titles = re.findall(r'<title>(.*?)</title>', content)
                
                for title in titles:
                    if not search_word or search_word in title.lower():
                        print(f"- {title}")
        except Exception as e:
            print(f"Не удалось прочитать {url}: {e}")

if __name__ == "__main__":
    main()
