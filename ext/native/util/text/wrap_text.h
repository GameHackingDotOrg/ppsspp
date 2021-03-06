#pragma once

#include <string>

class WordWrapper {
public:
	WordWrapper(const char *str, float maxW)
		: str_(str), maxW_(maxW) {
	}

	std::string Wrapped();

protected:
	virtual float MeasureWidth(const char *str, size_t bytes) = 0;
	void Wrap();
	void WrapBeforeWord();
	void AppendWord(int endIndex, bool addNewline);

	static bool IsCJK(uint32_t c);
	static bool IsPunctuation(uint32_t c);
	static bool IsSpace(uint32_t c);
	static bool IsShy(uint32_t c);

	const char *const str_;
	const float maxW_;
	std::string out_;
	// Index of last output / start of current word.
	int lastIndex_ = 0;
	// Index of last line start.
	int lastLineStart_ = 0;
	// Position the current word starts at.
	float x_ = 0.0f;
	// Most recent width of word since last index.
	float wordWidth_;
	// Force the next word to cut partially and wrap.
	bool forceEarlyWrap_ = false;
};
