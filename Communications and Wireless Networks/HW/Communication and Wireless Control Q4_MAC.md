109611066 吳典謀

## 1. What is the definition of modulation?

Modulation means to vary one or more properties of a periodic waveform (carrier signal) with a separate signal (modulation signal). The modulation signal contains the information that should be transferred. (<u>1</u>)

## 2. There are multiple modulation algorithms available for sending a given bit stream. Yes or No?

Yes, there are multiple modulation methods. Following list lists some categories: (<u>1</u>)

- **Analog modulation methods**: AM, FM, PM, QAM, SM, SSB
- **Digital modulation methods**: ASK, CPM, FSK
- **Hierarchical modulation methods**: QAM, WDM
- **Spread spectrum methods**: CSS, DSSS, FHSS, THSS

## 3. Assume that the symbol duration is T. If a modulation scheme embeds M bits in a symbol, what is the data rate of this modulation scheme?

The symbol rate $f$ can be calculated by symbol duration $T$: (<u>2</u>)

$$f = \frac{1}{T}$$

The data rate will be:

$$\text{data rate} = fM = \frac{M}{T}$$

## 4. How many unique patterns should we have if we want to embed M bits in a symbol?

When you have $M$ bits, the total number of unique combinations of these bits is $2^M$. Therefore, you need $2^M$ unique patterns.

## 5. Explain briefly what is the difference between PSK (phase-shift keying), FSK (frequency-shift keying), ASK (amplitude-shift keying)

- **PSK**: Phase-shift keying modulates the phase of a wave to convey data. (<u>3</u>)
- **FSK**: Frequency-shift keying switches between frequencies to transmit data. (<u>4</u>)
- **ASK**: Amplitude-shift keying represents the data as different amplitude of a wave. (<u>5</u>)

## Reference

1. “Modulation.” In Wikipedia, November 19, 2023. https://en.wikipedia.org/w/index.php?title=Modulation&oldid=1185852743.
2. “Symbol Rate.” In Wikipedia, December 23, 2023. https://en.wikipedia.org/w/index.php?title=Symbol_rate&oldid=1191388442.
3. “Phase-Shift Keying.” In Wikipedia, March 4, 2024. https://en.wikipedia.org/w/index.php?title=Phase-shift_keying&oldid=1211788782.
4. “Frequency-Shift Keying.” In Wikipedia, March 13, 2024. https://en.wikipedia.org/w/index.php?title=Frequency-shift_keying&oldid=1213527238.
5. “Amplitude-Shift Keying.” In Wikipedia, June 23, 2023. https://en.wikipedia.org/w/index.php?title=Amplitude-shift_keying&oldid=1161574964.