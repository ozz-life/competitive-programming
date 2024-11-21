package main

import (
	"fmt"
	"log"
	"net/http"
	"sync"
)

// Написать код, который будет выводить коды ответов на HTTP-запросы по двум URL адресам (например главная страница Google и главная страница Avito)
// Запросы должны осуществляться параллельно

func printCodes(urls []string, maxGos int) {
	var wg sync.WaitGroup

	cnt := len(urls)
	if cnt > maxGos {
		cnt = maxGos
	}

	wg.Add(cnt)
	get := func() {
		for url := range urls {
			resp, err := http.Get(url)
			if err != nil {
				log.Fatalln(err)
			}
			defer resp.Body.Close()
			fmt.Println(url, resp.Status)
		}
		defer wg.Done()
	}

	for i := 0; i < cnt; i++ {
		go get()
	}
	
	urlsChan := make(string, cnt)
	for _, url := range urls {
		urlsChan <- url
	}
	close(urlsChan)
	
	wg.Wait()
}

func main() {

}

// Следующий вопрос. Если мы хотим вызвать функцию для неопределённого количества урлов
// WaitGroup что это за структура и для чего важна
// Что такое горутина с точки зрения платформы?
// Слайс 500 урлов, будут ли они выполняться параллельно? А если их будет 600 тысяч, какие проблемы будут? Это Вопрос про файловый дескриптор.
// Как себя обезопасить от упирания в потолок по файловым дескрипторам? Либо делаем батчами. Либо ограничиваем количество запускаемых горутин
// Как получать данные из горутин?
// Какие каналы бывают?
// Что такое аксиомы каналов? 
