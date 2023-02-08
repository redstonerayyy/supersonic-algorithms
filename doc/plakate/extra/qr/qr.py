import qrcode
github = qrcode.make('https://github.com/Redstonerayy/supersonic-algorithms')
geeks = qrcode.make('https://en.wikipedia.org/wiki/Radix_sort')
pierre = qrcode.make('http://www.codercorner.com/RadixSortRevisited.htm')

github.save("github.png")
geeks.save("geeks.png")
pierre.save("pierre.png")