import type { PersonType } from "./Person.types";

export const Person = (props: PersonType) => {
    return (
        <div>
            {props.name.first} {props.name.last}
        </div>
    )
}