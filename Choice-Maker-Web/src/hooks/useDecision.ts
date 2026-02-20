import { useState } from "react";

export function useDecision() {
	const [answers, setAnswers] = useState<number[]>([]);

	const addAnswer = (score: number) => {
		setAnswers((prev) => [...prev, score]);
	};

	const totalScore = answers.reduce((a, b) => a + b, 0);

	const getDecision = () => {
		if (totalScore >= 5) return "Beli sekarang";
		if (totalScore >= 2) return "Mungkin butuh tapi tidak mendesak";
		if (totalScore >= -1) return "Tunda dulu";
		return "Impulsif — sebaiknya jangan beli";
	};

	return {
		answers,
		addAnswer,
		totalScore,
		getDecision,
	};
}
