all: create-input compile run test
zip: clean
	zip 109611066_hw_w11.zip 109611066_hw_01.cpp 109611066_hw_02.cpp
clean: clean-p1 clean-p2
	rm -f 109611066_hw_w11.zip

create-input: create-input-p1 create-input-p2
compile: compile-p1 compile-p2
run: run-p1 run-p2
test: test-p1 test-p2

create-input-p1:
	echo "Meet Sarah Turner, a diligent psychology student at Eastwood University. Despite her consistent efforts, a challenging midterm left her with a discouraging grade. Disheartened but determined, Sarah hit the books with renewed vigor, seeking guidance from professors and peers. As the final exam approached, Sarah's meticulous preparation became evident. She conquered each concept, mastering the intricacies of the subject. The exam day arrived, and Sarah faced it with confidence. When the results were released, a sense of accomplishment washed over her as she saw a remarkable improvement from the midterm. Sarah's story became a testament to resilience, proving that setbacks could be stepping stones to success. Her journey inspired her classmates and showcased the transformative power of dedication and hard work." > p1_input.txt
	echo "Tipe Ghvls Hbvypf, h htwwniye dzcnscssrj gayopba ee Pozxhzck Yytjlvdthf. Hpddpxp ssy gzygpwepba iqqcyxd, l qoewwsuktyu tmoesyq wpta lpc kpxs l rpwnziyertbn kclrl. Htdvlecesuio mia hpesyqtysk, Wlcoo lte hoi mzcrw htho vpysdio gwnsc, dslotyu nytoougp qfvq accmiddcyw lyr wipcg. Hw ess mmylz lblx owtczojlpo, Ghvls'g tietqbpzfg wvpaoyeetcu fpnoti pgwkiye. Goi nzbxypcsk ilnv jsynswx, xlgaictbn xsp wuxctqhgtpg vj ess zymusjx. Ess lblx rhc lcfpzpo, ouh Dlfhl qlqlh te kpxs ncujtosugp. Hvlr ess yidfzaw hpfl vpwshwpo, o ziyds vj lnqvqawwzlxpba aldvlh zgsy lpc oz wsp gha l cstecvoipp tawvzgstiye tysx evl qtohlvx. Doyes'd gascj plglxs h xpdhhqpyh as cpgpptpbji, acccmyr hoee dsaflnyz gzfzk fp dhltatbn wezblw ez gbgnpgz. Lpc xvycysf myddpvpo vlv nwozwxlhlw lyr zlzhqhwpo hoi ecouwqzfteetjl tzhsy sq oskmnlhpsy lbk llcr dscv." > p1_output-ans.txt
compile-p1:
	gcc 109611066_hw_01.cpp -o 109611066_hw_01
run-p1:
	./109611066_hw_01
test-p1:
	diff p1_output.txt p1_output-ans.txt
clean-p1:
	rm -f p1_input.txt p1_output.txt 109611066_hw_01 p1_output-ans.txt

create-input-p2:
	echo "Meet Sarah Turner, a diligent psychology student at Eastwood University. Despite her consistent efforts, a challenging midterm left her with a discouraging grade. Disheartened but determined, Sarah hit the books with renewed vigor, seeking guidance from professors and peers. As the final exam approached, Sarah's meticulous preparation became evident. She conquered each concept, mastering the intricacies of the subject. The exam day arrived, and Sarah faced it with confidence. When the results were released, a sense of accomplishment washed over her as she saw a remarkable improvement from the midterm. Sarah's story became a testament to resilience, proving that setbacks could be stepping stones to success. Her journey inspired her classmates and showcased the transformative power of dedication and hard work." > p2_input_plaintext.txt
	echo "Tipe Ghvls Hbvypf, h htwwniye dzcnscssrj gayopba ee Pozxhzck Yytjlvdthf. Hpddpxp ssy gzygpwepba iqqcyxd, l qoewwsuktyu tmoesyq wpta lpc kpxs l rpwnziyertbn kclrl. Htdvlecesuio mia hpesyqtysk, Wlcoo lte hoi mzcrw htho vpysdio gwnsc, dslotyu nytoougp qfvq accmiddcyw lyr wipcg. Hw ess mmylz lblx owtczojlpo, Ghvls'g tietqbpzfg wvpaoyeetcu fpnoti pgwkiye. Goi nzbxypcsk ilnv jsynswx, xlgaictbn xsp wuxctqhgtpg vj ess zymusjx. Ess lblx rhc lcfpzpo, ouh Dlfhl qlqlh te kpxs ncujtosugp. Hvlr ess yidfzaw hpfl vpwshwpo, o ziyds vj lnqvqawwzlxpba aldvlh zgsy lpc oz wsp gha l cstecvoipp tawvzgstiye tysx evl qtohlvx. Doyes'd gascj plglxs h xpdhhqpyh as cpgpptpbji, acccmyr hoee dsaflnyz gzfzk fp dhltatbn wezblw ez gbgnpgz. Lpc xvycysf myddpvpo vlv nwozwxlhlw lyr zlzhqhwpo hoi ecouwqzfteetjl tzhsy sq oskmnlhpsy lbk llcr dscv." > p2_input_ciphertext.txt
compile-p2:
	gcc 109611066_hw_02.cpp -o 109611066_hw_02
run-p2:
	./109611066_hw_02
test-p2:
clean-p2:
	rm -f p2_input_plaintext.txt p2_input_ciphertext.txt 109611066_hw_02