build: svgs pngs
	latexmk -xelatex --shell-escape plakat1.tex

svgs:
	latexmk --shell-escape diagramm.tex
	pdf2svg diagramm.pdf diagramm.svg

pngs:
	convert -density 500 -resize 400% diagramm.svg diagramm.png

clean:
	rm *.svg
	rm *.pdf