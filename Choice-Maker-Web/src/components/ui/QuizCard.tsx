import type { Question } from "../../questions/decisionQuestions";

type Props = {
	data: Question;
	onAnswer: (score: number) => void;
};

export default function QuestionCard({ data, onAnswer }: Props) {
	return (
		<>
			<h2>{data.question}</h2>

			{data.options.map((opt, i) => (
				<button key={i} onClick={() => onAnswer(opt.score)}>
					{opt.label}
				</button>
			))}

			<button></button>
		</>
	);
}
